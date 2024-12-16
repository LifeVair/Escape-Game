// Fill out your copyright notice in the Description page of Project Settings.
#include "Room.h"

// Sets default values
ARoom::ARoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;
	
	PlayerSpawn = CreateDefaultSubobject<UArrowComponent>("PlayerSpawn");
	PlayerSpawn->SetupAttachment(DefaultSceneRoot);

}

bool ARoom::CheckRoomResult_Implementation()
{
	//Needs to be overwritten in the child BP
	return false;
}

void ARoom::UnlockKey_Implementation()
{
	//Needs to be overwritten in the child BP
	if (DebugRoomInformation)
	{
		UE_LOG(LogTemp, Display, TEXT("Key unlocked !"));
	}
}

bool ARoom::GetRoomValidated()
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

void ARoom::RoomSucceeded()
{
	OnRoomSucceeded.Broadcast();
}

