// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "InputActionValue.h"
#include "FlyAbility.generated.h"

/**
 * 
 */
UCLASS()
class BHW_API UFlyAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	// Override the ActivateAbility method
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	// Fly Ability Settings
	void GetGravityDirection(const FInputActionValue& Value, const FGameplayAbilityActorInfo* ActorInfo);
	void SetGravityDirection(const FGameplayAbilityActorInfo* ActorInfo);
	void FlySetUp();
	void FlyBreakDown();

};
