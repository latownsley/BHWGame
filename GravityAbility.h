// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GravityAbility.generated.h"

/**
 * 
 */
UCLASS()
class BHW_API UGravityAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	// Override the ActivateAbility method
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	//Gravity Setup/Breakdown
	void StartGravity(const FGameplayAbilityActorInfo* ActorInfo);
	void EndGravity();
	
};
