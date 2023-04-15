// Fill out your copyright notice in the Description page of Project Settings.


#include "HitChargeActor.h"
#include "FascinatingForestCharacter.h"

AHitChargeActor::AHitChargeActor()
{
	damage = 15;
	OnActorBeginOverlap.AddDynamic(this, &AHitChargeActor::OnOverlapBegin);
}

void AHitChargeActor::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<AFascinatingForestCharacter>(OtherActor) != nullptr)
		return;
	part->DestroyComponent();
	collision_part->SetVisibility(true);
	if (Cast<ACreatureCharacter>(OtherActor) != nullptr)
	{
		//ACreatureCharacter* for_hit = Cast<ACreatureCharacter>(OtherActor);
		//for_hit->recieveDamage(damage);
	}
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	Destroy();
}
