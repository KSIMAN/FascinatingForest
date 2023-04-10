// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeChargeActor.h"

AChangeChargeActor::AChangeChargeActor()
{
	damage = 0;
}

void AChangeChargeActor::FlyByDirection(FVector dir)
{
	FTimerDelegate TimerCallback;
	TimerCallback.BindLambda([this, dir]
		{
			AddActorWorldOffset(dir * speed);
		});
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, TimerCallback, 0.05f, true);
}
void AChangeChargeActor::RandomFly()
{

}
void AChangeChargeActor::OnOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	collision_part->SetVisibility(true);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	Destroy();
}
