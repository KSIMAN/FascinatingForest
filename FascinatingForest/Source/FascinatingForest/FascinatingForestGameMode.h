// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FascinatingForestCharacter.h"
#include "FascinatingForestGameMode.generated.h"

UCLASS(minimalapi)
class AFascinatingForestGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFascinatingForestGameMode();
	int time_left; //time in secs
	void onGameOverEvent();
	void onVictoryEvent();
	void addSheep();
	void removeSheep();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int seconds_left;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int sheeps;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int min_sheeps;
	int max_sheeps;
	AFascinatingForestCharacter* player;
	void MainTimer();
	virtual void BeginPlay() override;
	FTimerHandle timer_h;

};



