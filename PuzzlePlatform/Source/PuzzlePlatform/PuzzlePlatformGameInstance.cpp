// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformGameInstance.h"

UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer) {
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor!"));
}

void UPuzzlePlatformGameInstance::Init() {
	UE_LOG(LogTemp, Warning, TEXT("init"));
}

void UPuzzlePlatformGameInstance::Host() {
	GetEngine()->AddOnScreenDebugMessage(0, 2, FColor().Green, TEXT("Hosting"));

	GetWorld()->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformGameInstance::Join(const FString& Address) {
	GetEngine()->AddOnScreenDebugMessage(0, 4, FColor().Green,FString::Printf(TEXT("Join %s"), *Address));

	GetFirstLocalPlayerController()->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
