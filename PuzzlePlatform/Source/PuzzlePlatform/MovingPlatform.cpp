// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform() {
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay() {
	Super::BeginPlay();

	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	StartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0) {
		if (!HasAuthority()) return;

		FVector Location = GetActorLocation();
		Location += ((GlobalTargetLocation - StartLocation).GetSafeNormal()) * Speed * DeltaTime;
		SetActorLocation(Location);

		if ((Location - StartLocation).Size() >= (GlobalTargetLocation - StartLocation).Size()) {
			auto tmp = GlobalTargetLocation;
			GlobalTargetLocation = StartLocation;
			StartLocation = tmp;
		}
	}
    
}

void AMovingPlatform::AddActiveTrigger() {
	ActiveTriggers++;
}
void AMovingPlatform::RemoveActiveTrigger() {
	if (ActiveTriggers > 0)
		ActiveTriggers--;
}