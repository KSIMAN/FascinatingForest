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

}

void AChargeActor::MoveToPoint()
{
}

void AChargeActor::MoveByDirection(FVector dir)
{
	AddActorLocalOffset(dir);
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

