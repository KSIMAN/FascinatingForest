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
	onGameOverEvent();


}

void AFascinatingForestGameMode::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<AFascinatingForestCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), AFascinatingForestCharacter::StaticClass()));
	if (player == nullptr)
		return;
	
	//GetWorld()->GetTimerManager().SetTimer(timer_h, this, &AFascinatingForestGameMode::MainTimer, 1, true);

}
void AFascinatingForestGameMode::onGameOverEvent()
{
	SetPause(GetWorld()->GetFirstPlayerController());
	UUserWidget* wid = createWidgetFromRef(TEXT("/Game/Widgets/GameOver.GameOver_C"));
	if (wid != nullptr)
		wid->AddToViewport(200);
}

void AFascinatingForestGameMode::onVictoryEvent()
{
	SetPause(GetWorld()->GetFirstPlayerController());
	UUserWidget* wid = createWidgetFromRef(TEXT("/Game/Widgets/VictoryWidget.VictoryWidget_C"));
	if (wid != nullptr)
		wid->AddToViewport(200);
}

void AFascinatingForestGameMode::addSheep()
{
	sheeps++;
	if (player != nullptr)
		player->Base_Widget_ref->setSheepCount(sheeps);
}

void AFascinatingForestGameMode::removeSheep()
{
	if(--sheeps < min_sheeps)
	onGameOverEvent();
}

UUserWidget* AFascinatingForestGameMode::createWidgetFromRef(FString bp_ref)
{
	FStringClassReference MyWidgetClassRef = bp_ref;
	if (UClass* MyWidgetClass = MyWidgetClassRef.TryLoadClass<UUserWidget>())
	{
		UUserWidget* widget;
		widget = CreateWidget<UUserWidget>(GetWorld(), MyWidgetClass);
		return widget;
	}
	return nullptr;
}

void AFascinatingForestGameMode::MainTimer()
{
	player->Base_Widget_ref->setTimeLeft(seconds_left / 60, seconds_left %60);
	if (--seconds_left == 0)
	{
		if (sheeps <= max_sheeps)
			onVictoryEvent();
		else onGameOverEvent();
	}
}


