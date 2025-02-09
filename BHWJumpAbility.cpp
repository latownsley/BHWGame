// Fill out your copyright notice in the Description page of Project Settings.


#include "BHWJumpAbility.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"


void UBHWJumpAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	// Check if the actor has a valid Character reference
	if (ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get()))
	{
		// Make the Character Jump
		Character->Jump();
	}

	//End the Ability
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}