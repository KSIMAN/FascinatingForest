// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ChangeChargeActor.h"
#include "HitChargeActor.h"
#include "Components/ArrowComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "BaseWidget.h"
#include <mutex>
#include "FascinatingForestCharacter.generated.h"


UENUM(BlueprintType)
enum class EAnimationType : uint8
{
	Stand,
	Walk,
	Run,
	Jump,
	Hit,
	Charm
};

UCLASS(config=Game)
class AFascinatingForestCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AFascinatingForestCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EAnimationType anim_state;
	
	//Stamina info

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stamina)
		float health;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stamina)
		float max_health;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stamina)
		float max_mana;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stamina)
		float mana;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stamina)
		float damage;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stamina)
		UBaseWidget* Base_Widget_ref;
	UFUNCTION()
		void recieveDamage(float dam);
	UFUNCTION()
		void addMana(float man);
	UFUNCTION()
		bool isAlive();
	UFUNCTION()
		void Death();
	UFUNCTION()
		bool canCharm(float need_mana);

	

	//Spelling
	UFUNCTION()
		void MakeChangeSpell();
	UFUNCTION()
		void MakeHitSpell();
	UFUNCTION()
	void FillMana();


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = WizardSettings)
		bool is_charming;
	std::mutex anim_mutex;


	
	/** Resets HMD orientation in VR. */
	void OnResetVR();

	void MoveForward(float Value);

	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	virtual void Tick(float deltaTime) override;

	virtual void BeginPlay() override;
public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

