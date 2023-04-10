// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeChargeActor.h"

AChangeChargeActor::AChangeChargeActor()
{
	damage = 0;
	OnActorBeginOverlap.AddDynamic(this, &AChangeChargeActor::OnOverlapBegin);
}

void AChangeChargeActor::RandomFly()
{

}
void AChangeChargeActor::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	part->DestroyComponent();
	collision_part->SetVisibility(true);
	if (Cast<ACreatureCharacter>(OtherActor) != nullptr)
	{
		
	}
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	Destroy();
}
