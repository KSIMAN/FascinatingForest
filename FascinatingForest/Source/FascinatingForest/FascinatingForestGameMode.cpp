// Copyright Epic Games, Inc. All Rights Reserved.

#include "FascinatingForestGameMode.h"
#include "FascinatingForestCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AFascinatingForestGameMode::AFascinatingForestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	sheeps = 0;
	min_sheeps = 1;
	max_sheeps = 10;
	seconds_left = 600;
	

}

void AFascinatingForestGameMode::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<AFascinatingForestCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	GetWorld()->GetTimerManager().SetTimer(timer_h, this, &AFascinatingForestGameMode::MainTimer, 1, true);

}
void AFascinatingForestGameMode::onGameOverEvent()
{
	
}

void AFascinatingForestGameMode::onVictoryEvent()
{
}

void AFascinatingForestGameMode::addSheep()
{
	sheeps++;
}

void AFascinatingForestGameMode::removeSheep()
{
	if(--sheeps < min_sheeps)
	onGameOverEvent();
}

void AFascinatingForestGameMode::MainTimer()
{
	player->Base_Widget_ref->setTimeLeft(seconds_left / 60, seconds_left % 60);
	if (--seconds_left == 0)
	{
		if (sheeps <= max_sheeps)
			onVictoryEvent();
		else onGameOverEvent();
	}
}


