// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChargeActor.h"
#include "HitChargeActor.generated.h"

/**
 * 
 */
UCLASS()
class FASCINATINGFOREST_API AHitChargeActor : public AChargeActor
{
	GENERATED_BODY()
public:
		AHitChargeActor();
protected:
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
};
