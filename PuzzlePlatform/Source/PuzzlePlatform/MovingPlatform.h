// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:

	AMovingPlatform();

	UPROPERTY(EditAnywhere)
	float Speed = 20.f;
	UPROPERTY(EditAnywhere, Meta=(MakeEditWidget = true))
	FVector TargetLocation;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

private:
	FVector GlobalTargetLocation;
	FVector StartLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;

};
