// Copyright Epic Games, Inc. All Rights Reserved.

#include "DesignPatternGameMode.h"
#include "DesignPatternCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADesignPatternGameMode::ADesignPatternGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
