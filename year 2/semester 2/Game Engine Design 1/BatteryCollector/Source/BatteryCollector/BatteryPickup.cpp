// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"
#include "Components/StaticMeshComponent.h"

ABatteryPickup::ABatteryPickup() {
	GetMesh()->SetSimulatePhysics(true);
}

void ABatteryPickup::OnCollect_Implementation() {
	//Use Base Picup behaviour
	Super::OnCollect_Implementation();

	//destroy battery
	Destroy();
}

