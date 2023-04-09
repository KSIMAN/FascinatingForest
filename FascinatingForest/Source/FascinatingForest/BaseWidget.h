// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class FASCINATINGFOREST_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:	
	void setHealth(float health);
	
	void setMana(float mana);

	void SetMaxHealth(int health);

	void UpdateAllParams(float health, float mana, float max_health);
protected:
	UBaseWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;
	float ConvertToPercents(float val, int max_val);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UProgressBar* health_bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UProgressBar* mana_bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int max_health;
};
