// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CreatureCharacter.h"
#include "FascinatingForestCharacter.h"
#include "AngryCreatureCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FASCINATINGFOREST_API AAngryCreatureCharacter : public ACreatureCharacter
{
	GENERATED_BODY()
public:
	AAngryCreatureCharacter();
protected:
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
	
};
