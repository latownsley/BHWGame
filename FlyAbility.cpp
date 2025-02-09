// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyAbility.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"


void UFlyAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{ 
	// Check if the actor has a valid Character reference
	if (ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get()))
	{
		// Make the Character fly
		Character->GetCharacterMovement()->SetMovementMode(MOVE_Flying);

		//End the Ability
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
	}
}

void UFlyAbility::FlySetUp()
{
	// settings to fly
}

void UFlyAbility::FlyBreakDown()
{
	// return to normal 
}

void UFlyAbility::GetGravityDirection(const FInputActionValue& Value, const FGameplayAbilityActorInfo* ActorInfo)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// Get Character
	ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());

	if (Character->Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Character->Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		Character->GetGravityDirection();
		Character->AddMovementInput(ForwardDirection, MovementVector.Y);
		Character->AddMovementInput(RightDirection, MovementVector.X);
	}

}

void UFlyAbility::SetGravityDirection(const FGameplayAbilityActorInfo* ActorInfo)
{
	// Get Character
	ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	
	// Set Character Gravity
	Character->GetCharacterMovement()->GravityScale = 50.0;
}