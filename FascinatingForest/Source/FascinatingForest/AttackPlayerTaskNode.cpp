// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackPlayerTaskNode.h"
#include "FascinatingForestCharacter.h"
#include "CreatureAIController.h"
EBTNodeResult::Type UAttackPlayerTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACreatureAIController* ai_ref = Cast<ACreatureAIController>(OwnerComp.GetAIOwner());
	if (ai_ref)
	{
		UBlackboardComponent* bb_ref = ai_ref->GetBlackBoardComponent();

		AFascinatingForestCharacter* player_for_attack = Cast<AFascinatingForestCharacter>(bb_ref->GetValueAsObject("Target"));
		if (player_for_attack)
			ai_ref->MoveToActor(player_for_attack, -1.0f, false); //it will be recieve damage
	}
	return EBTNodeResult::Type();
}
