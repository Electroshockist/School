// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APickup::APickup() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	isActive = true;

	//create static mech component
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	//set the rootcomponent to meshcomponent
	RootComponent = PickupMesh;
}

// Called when the game starts or when spawned
void APickup::BeginPlay() {
	Super::BeginPlay();
	
}


//unused
// Called every frame
void APickup::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

bool APickup::GetIsActive() {
	return isActive;
}

void APickup::SetActive(bool status) {
	isActive = status;
}
