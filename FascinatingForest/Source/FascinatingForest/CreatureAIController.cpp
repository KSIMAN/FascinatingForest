// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureAIController.h"


ACreatureAIController::ACreatureAIController()
{
	btree_comp = CreateDefaultSubobject<UBehaviorTreeComponent>("Behavior Tree");
	bboard_comp = CreateDefaultSubobject<UBlackboardComponent>("Black Board");

	character_key = "Target";
}

void ACreatureAIController::OnPossess(APawn* InPawn)
{
	Super::Possess(InPawn);
	ACreatureCharacter * creature = Cast<ACreatureCharacter>(InPawn);
	if (creature)
	{

	}

}
