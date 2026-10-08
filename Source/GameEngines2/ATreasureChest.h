// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATreasureChest.generated.h"

class UBoxComponent;

UCLASS()
class GAMEENGINES2_API AATreasureChest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATreasureChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Treasure Mesh of type static mesh component
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> TreasureMesh;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UBoxComponent> BoxCollider;

	UFUNCTION()
	void Collected();

	UFUNCTION()
	void OnBeginOverlapComponentEvent(UPrimitiveComponent *
		OverlappedComponent, AActor * OtherActor,
		UPrimitiveComponent * OtherComp, int32
		OtherBodyIndex, bool bFromSweep, const FHitResult &
		SweepResult);

	void AddOnscreenDebugMessage(FString message, FColor color, float duration);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	bool bCollected;
};
