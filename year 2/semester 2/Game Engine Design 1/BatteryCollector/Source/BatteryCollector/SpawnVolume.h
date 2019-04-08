// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//spawnable pickup
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class APickup> Spawnable;

	FTimerHandle SpawnTimer;

	//minimum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayMin;

	//maximum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayMax;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//get Spawn Area
	FORCEINLINE class UBoxComponent* GetSpawnArea() const { return SpawnArea; }

	//gets point within spawn area to spawn item
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointinVolume();

	//toggle spawning
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SetSpawningActive(bool status);

private:
	//const char* category = "Spawning";
	//determines spawn area
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* SpawnArea;

	void SpawnPickup();

	//current spawn delay
	float SpawnDelay;

};
