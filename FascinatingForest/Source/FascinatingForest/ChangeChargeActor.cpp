// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeChargeActor.h"
#include "FascinatingForestCharacter.h"

AChangeChargeActor::AChangeChargeActor()
{
	damage = 0;
	OnActorBeginOverlap.AddDynamic(this, &AChangeChargeActor::OnOverlapBegin);
	creature_paths.Push(FStringClassReference("/Game/Blueprints/CrocodileBP.CrocodileBP_C"));
	creature_paths.Push(FStringClassReference("/Game/Blueprints/DragonBP.DragonBP_C"));

}

void AChangeChargeActor::RandomFly()
{

}
bool AChangeChargeActor::LoadCreatureBP(FSoftClassPath path, FTransform * actor_pos)
{
	FStringClassReference CreatureClassRef(path);
	if (UClass* CreatureClass = CreatureClassRef.TryLoadClass<ACreatureCharacter>())
	{
		GetWorld()->SpawnActor(CreatureClass, actor_pos);
		return true;
	}
	return false;
}
void AChangeChargeActor::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if(Cast<AFascinatingForestCharacter>(OtherActor)!=nullptr)
		return;
	part->DestroyComponent();
	collision_part->SetVisibility(true);
	if (Cast<ACreatureCharacter>(OtherActor) != nullptr)
	{
		ACreatureCharacter * old_char = Cast<ACreatureCharacter>(OtherActor);
		FTransform trans = old_char->GetActorTransform();;
		LoadCreatureBP(creature_paths[rand() % creature_paths.Num()], &trans);
		old_char->Destroy();
	}
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	Destroy();
}
