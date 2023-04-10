// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "ChargeActor.generated.h"

UCLASS()
class FASCINATINGFOREST_API AChargeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChargeActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UParticleSystemComponent * part;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCapsuleComponent* collider;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UParticleSystemComponent* collision_part;
	UFUNCTION()
		void MoveToPoint();
	UFUNCTION()
		void MoveByDirection(FVector dir);
	UFUNCTION()
		void MoveByTrajectory();
	float speed;
	int damage;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
