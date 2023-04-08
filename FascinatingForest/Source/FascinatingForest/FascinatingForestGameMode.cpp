// Copyright Epic Games, Inc. All Rights Reserved.

#include "FascinatingForestGameMode.h"
#include "FascinatingForestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFascinatingForestGameMode::AFascinatingForestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
