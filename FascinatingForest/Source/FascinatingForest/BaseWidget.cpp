// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWidget.h"

void UBaseWidget::setHealth(float health)
{
	health_bar->SetPercent(ConvertToPercents(health, max_health));
}

void UBaseWidget::setMana(float mana)
{
	mana_bar->SetPercent(ConvertToPercents(mana, 100));
}
void UBaseWidget::SetMaxHealth(int health)
{
	max_health = health;
}
void UBaseWidget::UpdateAllParams(float health, float mana, float m_health)
{
	setHealth(health);
	setMana(mana);
	SetMaxHealth(m_health);
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