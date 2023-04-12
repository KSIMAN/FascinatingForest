// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChargeActor.h"
#include "CreatureCharacter.h"
#include "ChangeChargeActor.generated.h"

/**
 * 
 */
UCLASS()
class FASCINATINGFOREST_API AChangeChargeActor : public AChargeActor
{
	GENERATED_BODY()
public:
	AChangeChargeActor();
	TArray<FSoftClassPath> creature_paths;
	UFUNCTION()
	void RandomFly();
	bool LoadCreatureBP(FSoftClassPath path, FTransform * actor_pos);
protected:

	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
};
