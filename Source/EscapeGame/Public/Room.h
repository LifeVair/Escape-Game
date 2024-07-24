// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRoomSucceeded);

UCLASS()
class ESCAPEGAME_API ARoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RoomValidated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform PlayerSpawnTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DEBUG")
	bool DebugRoomInformation;

	UPROPERTY(BlueprintAssignable, Category="EventDispatcher")
	FOnRoomSucceeded OnRoomSucceeded;
	
	//Return the state of the room
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GetRoomValidated();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SpawnPlayer(FTransform SpawnTransform);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UnlockKey();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CheckRoomResult();
	virtual bool CheckRoomResult_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RoomSucceeded();
	virtual void RoomSucceeded_Implementation();
};