// Copyright Epic Games, Inc. All Rights Reserved.

#include "FascinatingForestCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// AFascinatingForestCharacter

AFascinatingForestCharacter::AFascinatingForestCharacter()
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

	anim_state = EAnimationType::Stand;
	is_charming = false;
	health = 100;
	max_health = 100;
	mana = 200;
	damage = 15;

}

void AFascinatingForestCharacter::Tick(float deltaTime)
{
	if (GetVelocity().IsZero() && !is_charming)
	{
		anim_mutex.lock();
		anim_state = EAnimationType::Stand;
		anim_mutex.unlock();
	}
}

void AFascinatingForestCharacter::BeginPlay()
{
	Super::BeginPlay();
	FStringClassReference MyWidgetClassRef(TEXT("/Game/Widgets/BaseWidget.BaseWidget_C"));
	if (UClass* MyWidgetClass = MyWidgetClassRef.TryLoadClass<UUserWidget>())
	{
		UUserWidget* BaseHUDBP_ref;
		BaseHUDBP_ref = CreateWidget<UUserWidget>(GetWorld(), MyWidgetClass);
		Base_Widget_ref = Cast<UBaseWidget>(BaseHUDBP_ref);
		if (Base_Widget_ref != nullptr)
			Base_Widget_ref->AddToViewport(10);
		Base_Widget_ref->UpdateAllParams(health, mana, max_health);

	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AFascinatingForestCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveRight", this, &AFascinatingForestCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AFascinatingForestCharacter::MoveForward);


	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFascinatingForestCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFascinatingForestCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AFascinatingForestCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AFascinatingForestCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AFascinatingForestCharacter::OnResetVR);
}


void AFascinatingForestCharacter::recieveDamage(float damage)
{
	health -= damage;
	if (isAlive())
		Base_Widget_ref->setHealth(health);
	else Death();
}

bool AFascinatingForestCharacter::isAlive()
{
	if (health > 0)
		return true;
	else return false;
}

void AFascinatingForestCharacter::Death()
{
}

bool AFascinatingForestCharacter::canCharm(float need_mana)
{
	if ((mana - need_mana) >= 0)
		return true;
	else return false;
}

void AFascinatingForestCharacter::MakeChangeSpell()
{
}

void AFascinatingForestCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AFascinatingForestCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AFascinatingForestCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AFascinatingForestCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFascinatingForestCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AFascinatingForestCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
		anim_mutex.lock();
		anim_state = EAnimationType::Walk;
		anim_mutex.unlock();
	}

}

void AFascinatingForestCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
		anim_mutex.lock();
		anim_state = EAnimationType::Walk;
		anim_mutex.unlock();
	}
	
}
