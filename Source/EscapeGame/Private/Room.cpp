// Fill out your copyright notice in the Description page of Project Settings.
#include "Room.h"

// Sets default values
ARoom::ARoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ARoom::CheckRoomResult_Implementation()
{
	//Needs to be overwritten in the child BP
	return false;
}

void ARoom::RoomSucceeded_Implementation()
{
	
}

void ARoom::UnlockKey_Implementation()
{
	//Needs to be overwritten in the child BP
	if (DebugRoomInformation)
	{
		UE_LOG(LogTemp, Display, TEXT("Key unlocked !"));
	}
}

void ARoom::SpawnPlayer_Implementation(FTransform SpawnTransform)
{
	if (DebugRoomInformation)
	{
		UE_LOG(LogTemp,Display,TEXT("Spawning player"));
	}
}


bool ARoom::GetRoomValidated_Implementation()
{
	return RoomValidated;
}


// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

