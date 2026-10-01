// Fill out your copyright notice in the Description page of Project Settings.


#include "ATreasureChest.h"
#include "Components/BoxComponent.h"

// Sets default values
AATreasureChest::AATreasureChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialilize the Treasure Mesh
	TreasureMesh = CreateDefaultSubobject<UStaticMeshComponent>("TreasureMesh");

	TreasureMesh->SetGenerateOverlapEvents(false);

	//Initialize the Box Collider
	BoxCollider = CreateDefaultSubobject<UBoxComponent>("Collision Detection");

	//Set up the root component
	SetRootComponent(BoxCollider);

	//Parent the treasure mesh component to the box collider
	TreasureMesh->SetupAttachment(BoxCollider);

	bCollected = false;

}

// Called when the game starts or when spawned
void AATreasureChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATreasureChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AATreasureChest::CollectTreasure()
{
	if (!bCollected)
	{
		bCollected = true;
		// Hide the treasure mesh
		TreasureMesh->SetVisibility(false);
		// Disable collision
		BoxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}