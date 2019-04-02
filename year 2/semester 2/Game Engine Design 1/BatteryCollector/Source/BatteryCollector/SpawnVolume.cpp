// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnVolume.h"
#include "TimerManager.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Pickup.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//create spawn area
	SpawnArea = CreateDefaultSubobject<UBoxComponent>("Spawn Area");
	RootComponent = SpawnArea;

	//set default spawn delay range
	SpawnDelayMin = 1.0f;
	SpawnDelayMax = 4.5f;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	DelaySpawning();
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetRandomPointinVolume()
{
	FVector SpawnOrigin = SpawnArea->Bounds.Origin;
	FVector SpawnExtent = SpawnArea->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin,SpawnExtent);
}

void ASpawnVolume::SpawnPickup() {
	if (Spawnable != NULL) {
		//check for valid world
		UWorld* const World = GetWorld();
		if (World) {
			//set spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			//get random location
			FVector SpawnLocation = GetRandomPointinVolume();

			//randomize pickup orientation
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			//spawn pickup
			APickup* const SpawnedPickup = World->SpawnActor<APickup>(Spawnable, SpawnLocation, SpawnRotation, SpawnParams);

			DelaySpawning();
		}
	}
}

