// Fill out your copyright notice in the Description page of Project Settings.


#include "AngryCreatureCharacter.h"

AAngryCreatureCharacter::AAngryCreatureCharacter()
{
	OnActorBeginOverlap.AddDynamic(this, &AAngryCreatureCharacter::OnOverlapBegin);
}

void AAngryCreatureCharacter::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<AFascinatingForestCharacter>(OtherActor) != nullptr)
	{
		AFascinatingForestCharacter* to_hit = Cast<AFascinatingForestCharacter>(OtherActor);
		to_hit->recieveDamage(damage);
	}
}
