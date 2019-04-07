// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//determines whether actor is active
	bool isActive;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//return pickup mesh
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	//get isActive
	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool GetIsActive();

	//set isActive
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetIsActive(bool satus);

	//called on pickup
	UFUNCTION(BlueprintNativeEvent)
		void OnCollect();
	virtual void OnCollect_Implementation();

private:
	//static mesh
	UPROPERTY(visibleAnyWhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PickupMesh;

};
