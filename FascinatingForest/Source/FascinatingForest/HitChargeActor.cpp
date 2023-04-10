// Fill out your copyright notice in the Description page of Project Settings.


#include "HitChargeActor.h"

AHitChargeActor::AHitChargeActor()
{
	OnActorBeginOverlap.AddDynamic(this, &AHitChargeActor::OnOverlapBegin);
	damage = 15;
}

void AHitChargeActor::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	part->DestroyComponent();
	collision_part->SetVisibility(true);
	if (Cast<ACreatureCharacter>(OtherActor) != nullptr)
	{
		ACreatureCharacter* for_hit = Cast<ACreatureCharacter>(OtherActor);
		for_hit->recieveDamage(damage);
	}
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	Destroy();
}
