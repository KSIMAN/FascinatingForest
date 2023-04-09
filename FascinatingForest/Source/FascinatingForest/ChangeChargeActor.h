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
protected:

	void OnOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
