// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattaryGameGameMode.h"
#include "BattaryGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABattaryGameGameMode::ABattaryGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
