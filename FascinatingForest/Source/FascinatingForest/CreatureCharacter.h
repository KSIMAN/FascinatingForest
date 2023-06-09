// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "CreatureCharacter.generated.h"

UENUM(BlueprintType)
enum class EAnimationAnimalType : uint8
{
	Stand,
	Walk,
	Hit,
	Dead
};
UCLASS()
class FASCINATINGFOREST_API ACreatureCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACreatureCharacter();
	void recieveDamage(int dam); //make interface later
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* box;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		EAnimationAnimalType a_state;
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* bh_tree;
	UPROPERTY(EditAnywhere)
		class UPawnSensingComponent * pawn_sensing;
	UFUNCTION()
		int getDamage();
	UPROPERTY(VisibleAnywhere)
	EAnimationAnimalType anim_state;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int damage;
	
	UFUNCTION()
	void Death();
	UFUNCTION()
		void onPlayerVisible(APawn* pawn); //when player caugtht
	
	enum MindState {KIND, NEUTRAL, ANGRY };
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
