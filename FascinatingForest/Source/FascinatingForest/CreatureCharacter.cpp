// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureCharacter.h"
#include "CreatureAIController.h"

// Sets default values
ACreatureCharacter::ACreatureCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*Init objects*/
	box = CreateDefaultSubobject<UBoxComponent>("Collider");
	pawn_sensing = CreateDefaultSubobject<UPawnSensingComponent>("Vision of AI");
	
	/*Scene setup*/
	box->SetupAttachment(RootComponent);

	/*Setup Sense Component*/
	pawn_sensing->SetPeripheralVisionAngle(30);

	/*Init variables*/
	a_state = EAnimationAnimalType::Stand;
	health = 10;
	damage = 0;
}

void ACreatureCharacter::recieveDamage(int dam)
{
	health -= dam;
	if (health <= 0)
		Death();
}

// Called when the game starts or when spawned
void ACreatureCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (pawn_sensing)
		pawn_sensing->OnSeePawn.AddDynamic(this, &ACreatureCharacter::onPlayerVisible);
	
}

void ACreatureCharacter::Death()
{
	a_state = EAnimationAnimalType::Dead;
	FTimerDelegate TimerCallback;
	TimerCallback.BindLambda([this]
		{
			Destroy();
		});
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, TimerCallback, 5.0f, false);
}

void ACreatureCharacter::onPlayerVisible(APawn* pawn)
{
	ACreatureAIController* ai_ref = Cast<ACreatureAIController>(GetController());
	if (!ai_ref)
		return;
	ai_ref->setPlayerCaught(pawn);

}

// Called every frame
void ACreatureCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACreatureCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

