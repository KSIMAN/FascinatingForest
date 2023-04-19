// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWidget.h"

void UBaseWidget::setHealth(float health)
{
	health_bar->SetPercent(ConvertToPercents(health, max_health));
	
}

void UBaseWidget::setMana(float mana)
{
	mana_bar->SetPercent(ConvertToPercents(mana, 100));
	setSheepCount(666);
}
void UBaseWidget::setMaxHealth(int health)
{
	max_health = health;
}
void UBaseWidget::updateAllParams(float health, float mana, float m_health)
{
	setMaxHealth(m_health);
	setHealth(health);
	setMana(mana);

}
void UBaseWidget::setTimeLeft(int minutes, int seconds)
{
	FString val = FString( FString::FromInt(minutes)+ ":"+ FString::FromInt(seconds));
	time_left->SetText(FText::FromString(val));
}
void UBaseWidget::setSheepCount(int count)
{
	FString val = FString::FromInt(count);
	time_left->SetText(FText::FromString(val));
}
float UBaseWidget::ConvertToPercents(float val, int max_val)
{
	return ((100 * val) / max_val) / 100;
}
UBaseWidget::UBaseWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UBaseWidget::NativeConstruct()
{
	Super::NativeConstruct();
}