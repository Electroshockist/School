// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "SpawnVolume.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/PawnMovementComponent.h"


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

void ABatteryCollectorGameMode::BeginPlay() {
	Super::BeginPlay();

	//get all spawn volumes in scene
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		ASpawnVolume* spawnVolume = Cast<ASpawnVolume>(Actor);
		if (spawnVolume) {
			spawnVolumes.AddUnique(spawnVolume);
		}
	}

	setPlayState(EBatteryPlayState::EPlaying);

	//set score to beat
	ABatteryCollectorCharacter* character = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (character) {
		winPowerThreshold = character->GetBasePowerLevel() * 1.25f;
	}

	if (HUDWidgetClass != nullptr) {
		currentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (currentWidget != nullptr) {
			currentWidget->AddToViewport();
		}
	}
}

void ABatteryCollectorGameMode::Tick(float deltaTime) {
	Super::Tick(deltaTime);

	//check that we are using battery collector character
	ABatteryCollectorCharacter* character = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this,0));
	if (character) {
		//if character power >= win threshold, set game state to won
		if (character->GetPowerLevel() >= winPowerThreshold) {
			setPlayState(EBatteryPlayState::EWon);
		}
		//if character's power is positive
		else if (character->GetPowerLevel() > 0) {
			//drain power using decayRate
			character->UpdatePower(-deltaTime * decayRate * character->GetBasePowerLevel());
		}
		else {
			setPlayState(EBatteryPlayState::EGameOver);
		}
	}
}

float ABatteryCollectorGameMode::getWinPowerThreshold() const {
	return winPowerThreshold;
}

EBatteryPlayState ABatteryCollectorGameMode::getPlayState() const{
	return playState;
}

void ABatteryCollectorGameMode::setPlayState(EBatteryPlayState newPlayState) {
	//set current state
	playState = newPlayState;
	//handle current state
	HandleNewState(newPlayState);
}

void ABatteryCollectorGameMode::HandleNewState(EBatteryPlayState newPlayState) {
	switch (newPlayState) {
		//if game is playing
		case EBatteryPlayState::EPlaying:
			//spawn volumes active
			for (ASpawnVolume* spawnVolume : spawnVolumes) {
				spawnVolume->SetSpawningActive(true);
			}
			break;
		//if game won
		case EBatteryPlayState::EWon:
			//spawn volumes inactive
			for (ASpawnVolume* spawnVolume : spawnVolumes) {
				spawnVolume->SetSpawningActive(false);
			}
			break;
		//if game over
		case EBatteryPlayState::EGameOver: {
				//spawn volumes inactive
				for (ASpawnVolume* spawnVolume : spawnVolumes) {
					spawnVolume->SetSpawningActive(false);
				}
				//disable player input
				APlayerController* playerController = UGameplayStatics::GetPlayerController(this, 0);

				if (playerController) {
					playerController->SetCinematicMode(true, false, false, true, false);
				}
				//ragdoll player
				ACharacter* character = UGameplayStatics::GetPlayerCharacter(this, 0);
				if (character) {
					character->GetMesh()->SetSimulatePhysics(true);
					character->GetMovementComponent()->MovementState.bCanJump = false;
				}
			}
			break;
		//if state unknown
		default:
		case EBatteryPlayState::EUnknown: {

		}
			break;
	}
}
