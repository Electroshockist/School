// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	//base decay rate
	decayRate = 0.01f;
}

void ABatteryCollectorGameMode::Tick(float deltaTime) {
	Super::Tick(deltaTime);

	//check that we are using battery collector character
	ABatteryCollectorCharacter* character = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this,0));
	if (character) {
		//if character's power is positive
		if (character->GetBasePowerLevel() > 0) {
			//drain power using decayRate
			character->UpdatePower(-deltaTime * decayRate * character->GetBasePowerLevel());
		}
	}
}
