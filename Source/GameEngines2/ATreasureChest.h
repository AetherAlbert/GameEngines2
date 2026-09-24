// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATreasureChest.generated.h"

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
