// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplaySystemGameMode.h"
#include "GameplaySystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameplaySystemGameMode::AGameplaySystemGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
