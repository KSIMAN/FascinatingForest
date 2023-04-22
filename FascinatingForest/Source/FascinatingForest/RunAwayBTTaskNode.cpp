// Fill out your copyright notice in the Description page of Project Settings.


#include "RunAwayBTTaskNode.h"
#include "FascinatingForestCharacter.h"
#include "CreatureAIController.h"

EBTNodeResult::Type URunAwayBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACreatureAIController* ai_ref = Cast<ACreatureAIController>(OwnerComp.GetAIOwner());
	if (ai_ref)
	{
		UBlackboardComponent* bb_ref = ai_ref->GetBlackBoardComponent();

		AFascinatingForestCharacter* player_run_from = Cast<AFascinatingForestCharacter>(bb_ref->GetValueAsObject("Target"));
		if (player_run_from)
		{
			FVector dir = player_run_from->GetActorForwardVector();
			FVector location = ai_ref->GetPawn()->GetActorLocation() + dir * (120 + rand() % 300);
			ai_ref->setLocationToGo(location);
			ai_ref->MoveToLocation(location, -1.0f, true, true, false, false, 0, false);
		}
	}
	return EBTNodeResult::Type();
}
