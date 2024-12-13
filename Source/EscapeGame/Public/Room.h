// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
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

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Give the validation status of the room
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RoomValidated;

	// Time (in seconds) available to resolve the room 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Blueprintable)
	int AvailableTimeToResolve;
	
	// Give the transform where we want the player to spawn in the room
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DEBUG")
	bool DebugRoomInformation;

	// Dispatcher allowing to know when a room is succeeded 
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnRoomSucceeded OnRoomSucceeded;

	UFUNCTION(BlueprintCallable, Category = "Events")
	void RoomSucceeded();
	
	// Is used to spawn the playerspawn arrow 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="components")
	USceneComponent* DefaultSceneRoot;

	// Arrow indicating the player spawn location
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="components")
	UArrowComponent* PlayerSpawn;
	
	//Return the state of the room
	UFUNCTION(BlueprintCallable, BlueprintGetter)
	bool GetRoomValidated();

	
	
	//Unlock the key of the game (most of the time a filter), should be overriden depending on need 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UnlockKey();

	//Return true if the room is succeeded
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CheckRoomResult();
	virtual bool CheckRoomResult_Implementation();
};