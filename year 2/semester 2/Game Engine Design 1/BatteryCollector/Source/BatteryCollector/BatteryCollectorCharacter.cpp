// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Pickup.h"
#include "BatteryPickup.h"

//////////////////////////////////////////////////////////////////////////
// ABatteryCollectorCharacter

ABatteryCollectorCharacter::ABatteryCollectorCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//create collection sphere
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->AttachTo(RootComponent);
	CollectionSphere->SetSphereRadius(200.0f);

	//set character's base power level
	basePowerLevel = 2000.0f;

	powerLevel = basePowerLevel;

	//set speed based off powerlevel
	speedFactor = 0.75f;
	baseSpeed = 10.0f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ABatteryCollectorCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Collect", IE_Pressed, this, &ABatteryCollectorCharacter::CollectPickups);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABatteryCollectorCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABatteryCollectorCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ABatteryCollectorCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ABatteryCollectorCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ABatteryCollectorCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ABatteryCollectorCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ABatteryCollectorCharacter::OnResetVR);
}


void ABatteryCollectorCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ABatteryCollectorCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ABatteryCollectorCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ABatteryCollectorCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABatteryCollectorCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABatteryCollectorCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ABatteryCollectorCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void ABatteryCollectorCharacter::CollectPickups() {
	//get all overlaping actors and store in array
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);

	//keep track of collected power
	float collectedPower = 0;

	//for each actor we collect
	for (size_t iCollected = 0; iCollected < CollectedActors.Num(); iCollected++) {
		//cast actor to APickup
		APickup* const tempPickup = Cast<APickup>(CollectedActors[iCollected]);

		//if cast successful and pickup is valid and active
		if (tempPickup && !tempPickup->IsPendingKill() && tempPickup->GetIsActive()) {

			//call pickup's OnCollect
			tempPickup->OnCollect();

			//check to see if pickup is battery
			ABatteryPickup* const tempBattery = Cast<ABatteryPickup>(tempPickup);
			if (tempBattery) {
				//increase collected power
				collectedPower += tempBattery->GetBatteryPower();
			}

			//deactivate pickup
			tempPickup->SetIsActive(false);
		}
	}
	if (collectedPower > 0) {
		UpdatePower(collectedPower);
	}
}

float ABatteryCollectorCharacter::GetBasePowerLevel() {
	return basePowerLevel;
}

float ABatteryCollectorCharacter::GetPowerLevel() {
	return powerLevel;
}

//called whenever power is updated
void ABatteryCollectorCharacter::UpdatePower(float powerChange){
	//update power level
	powerLevel += powerChange;

	//update speed
	GetCharacterMovement()->MaxWalkSpeed = baseSpeed + speedFactor * powerLevel;

	//call visual effect
	powerChangeEffect();
}


