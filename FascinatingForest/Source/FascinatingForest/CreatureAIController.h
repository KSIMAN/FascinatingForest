// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CreatureCharacter.h"
#include "AIController.h"
#include "CreatureAIController.generated.h"


UCLASS()
class FASCINATINGFOREST_API ACreatureAIController : public AAIController
{
	GENERATED_BODY()

	UBehaviorTreeComponent* btree_comp;

	UBlackboardComponent* bboard_comp;

	//for BlackBoard
	UPROPERTY(EditDefaultsOnly)
		FName character_key;

	virtual void OnPossess(APawn* InPawn) override;
	

public:
	ACreatureAIController();

	FORCEINLINE UBlackboardComponent* GetBlackBoardComponent() const { return bboard_comp;  };
};
