// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"
#include "Components/StaticMeshComponent.h"

ABatteryPickup::ABatteryPickup() {
	GetMesh()->SetSimulatePhysics(true);

	//base power level of the battery
	batteryPower = 150.0f;
}

void ABatteryPickup::OnCollect_Implementation() {
	//Use Base Picup behaviour
	Super::OnCollect_Implementation();

	//destroy battery
	Destroy();
}

//battery power getter
float ABatteryPickup::GetBatteryPower() {
	return batteryPower;
}

