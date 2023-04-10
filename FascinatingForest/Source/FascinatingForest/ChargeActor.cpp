// Fill out your copyright notice in the Description page of Project Settings.


#include "ChargeActor.h"

// Sets default values
AChargeActor::AChargeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	collider = CreateDefaultSubobject<UCapsuleComponent>("Collider");
	part = CreateDefaultSubobject<UParticleSystemComponent>("Particles");
	collision_part = CreateDefaultSubobject<UParticleSystemComponent>("Collision Particles");
	RootComponent = collider;
	part->SetupAttachment(collider);
	collision_part->SetupAttachment(collider);
	collision_part->SetVisibility(false);
	speed = 2.0f;
	SetActorRotation(FRotator(0, 0, 90));

}

void AChargeActor::MoveToPoint()
{
}

void AChargeActor::MoveByDirection(FVector dir)
{
	FTimerDelegate TimerCallback;
	TimerCallback.BindLambda([this, dir]
		{
			AddActorLocalOffset(dir * speed);
		});
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, TimerCallback, 0.05f, true);
}

void AChargeActor::MoveByTrajectory()
{
}

// Called when the game starts or when spawned
void AChargeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChargeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(0,3,0));

}

