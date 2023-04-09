// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeChargeActor.h"

AChangeChargeActor::AChangeChargeActor()
{
	
}

void AChangeChargeActor::OnOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	collision_part->SetVisibility(true);
}
