// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackPlayerTaskNode.h"
#include "FascinatingForestCharacter.h"
#include "AngryCreatureCharacter.h"
#include "CreatureAIController.h"
EBTNodeResult::Type UAttackPlayerTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACreatureAIController* ai_ref = Cast<ACreatureAIController>(OwnerComp.GetAIOwner());
	if (ai_ref)
	{
		UBlackboardComponent* bb_ref = ai_ref->GetBlackBoardComponent();

		AFascinatingForestCharacter* player_for_attack = Cast<AFascinatingForestCharacter>(bb_ref->GetValueAsObject("Target"));
		AAngryCreatureCharacter* controll_pawn = Cast<AAngryCreatureCharacter>(ai_ref->GetPawn());
		if (player_for_attack && controll_pawn)
		{
			player_for_attack->recieveDamage(controll_pawn->getDamage());
			player_for_attack->GetCapsuleComponent()->AddForce(controll_pawn->GetActorForwardVector()*300);
		}
			
	}
	return EBTNodeResult::Type();
}
