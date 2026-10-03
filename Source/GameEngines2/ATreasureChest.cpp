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
	
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AATreasureChest::OnBeginOverlapComponentEvent);

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
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Treasure Not Collected!"));
	
}

void AATreasureChest::Collected()
{
	
	TreasureMesh->SetVisibility(false);
	TreasureMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	

}

void AATreasureChest::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
	const FHitResult& SweepResult)
{
	//Cast to character other actor -> object of Character overlap
	// Hint is constructor and AddDynamic
	if (OtherActor && OtherActor != this) {
		AddOnscreenDebugMessage(TEXT("Treasure Collected!"), FColor::Cyan, 5.0f);
		bCollected = true;
		Collected();
	}
	
}

void AATreasureChest::AddOnscreenDebugMessage(FString message, FColor color, float duration)
{
	GEngine->AddOnScreenDebugMessage(-1, duration, color, message);
}


// Called every frame
void AATreasureChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

