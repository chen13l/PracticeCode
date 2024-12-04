// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySystem/Public/Game/Player/BasePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Game/Player/BasePlayerState.h"
#include "Interfaces/ItemInteraction.h"
#include "InventorySystem/InventoryComp.h"

ABasePlayerController::ABasePlayerController()
{
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem && !Subsystem->HasMappingContext(MappingContext)) { Subsystem->AddMappingContext(MappingContext, 0); }
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(TestAction, ETriggerEvent::Triggered, this, &ABasePlayerController::Pick);
	}
}

void ABasePlayerController::Pick()
{
	if (IsLocalController())
	{
		ServerPick();
	}
}

void ABasePlayerController::ServerPick_Implementation()
{
	ABasePlayerState* BasePlayerState = GetPlayerState<ABasePlayerState>();
	if (BasePlayerState && BasePlayerState->GetInventoryComp())
	{
		BasePlayerState->GetInventoryComp()->Pick();
	}
}
