// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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

};



