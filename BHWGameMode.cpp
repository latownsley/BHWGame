// Copyright Epic Games, Inc. All Rights Reserved.

#include "BHWGameMode.h"
#include "BHWCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABHWGameMode::ABHWGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
