// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureAIController.h"


ACreatureAIController::ACreatureAIController()
{
	btree_comp = CreateDefaultSubobject<UBehaviorTreeComponent>("Behavior Tree");
	bboard_comp = CreateDefaultSubobject<UBlackboardComponent>("Black Board");

	character_key = "Target";
	location_to_go_key = "LocationToGo";
}

void ACreatureAIController::OnPossess(APawn* InPawn)
{
	Super::Possess(InPawn);
	ACreatureCharacter * creature = Cast<ACreatureCharacter>(InPawn);
	if (creature)
	{
		bboard_comp->InitializeBlackboard(*(creature->bh_tree->BlackboardAsset));
		btree_comp->StartTree(*(creature->bh_tree));
	}
	
}

void ACreatureAIController::setPlayerCaught(APawn* pawn)
{
	if (!bboard_comp)
		return;
	bboard_comp->SetValueAsObject(character_key, pawn);

}

void ACreatureAIController::setLocationToGo(FVector loc)
{
	if (!bboard_comp)
		return;
	bboard_comp->SetValueAsVector(location_to_go_key, loc);
}
