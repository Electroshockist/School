// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

//enum to store gameplay state
UENUM(BlueprintType)
enum  class EBatteryPlayState : uint8 {
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Power")
	float getWinPowerThreshold() const;

	virtual void BeginPlay() override;

	//returns current play state
	UFUNCTION(BlueprintPure, Category = "Power")
	EBatteryPlayState getPlayState() const;

	//set new play state
	void setPlayState(EBatteryPlayState newPlayState);

protected:
	//the rate of character's power decay
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (Blueprintprotected = "true"))
	float decayRate;

	//threshold of power required to win
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (Blueprintprotected = "true"))
	float winPowerThreshold;

	//Hud
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (Blueprintprotected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	//the instance of HUDWidgetClass
	UPROPERTY()
	class UUserWidget* currentWidget;

private:
	//stores current play state
	EBatteryPlayState playState;

	TArray<class ASpawnVolume*> spawnVolumes;

	//handle function calls that rely upon changing the state of the game
	void HandleNewState(EBatteryPlayState newState);
};

