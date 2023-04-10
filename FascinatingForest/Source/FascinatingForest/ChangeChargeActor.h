// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChargeActor.h"
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

	UFUNCTION()
	void RandomFly();
protected:

	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
};
