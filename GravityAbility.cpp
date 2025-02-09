// Fill out your copyright notice in the Description page of Project Settings.

#include "GravityAbility.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"


void UGravityAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	// Check if the actor has a valid Character reference
	if (ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get()))
	{
		// Change Gravity
		StartGravity(ActorInfo);

		//End the Ability
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		//EndGravity();
	}
}

void UGravityAbility::StartGravity(const FGameplayAbilityActorInfo* ActorInfo)
{
	
	// Check if the actor has a valid Character reference
	if (ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get()))
	{
		// find vectors
		FVector currentDirection = Character->GetActorForwardVector();
		FVector newDirection = -currentDirection;

		// set character gravity
		Character->GetCharacterMovement()->SetGravityDirection(newDirection);
	}
}

void UGravityAbility::EndGravity()
{
	// Set thing back to normal? Do I need this?
}