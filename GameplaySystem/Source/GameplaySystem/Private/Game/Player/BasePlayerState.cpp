// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySystem/Public/Game/Player/BasePlayerState.h"

#include "GameplaySystem/Public/InventorySystem/InventoryComp.h"

ABasePlayerState::ABasePlayerState()
{
	InventoryComp = CreateDefaultSubobject<UInventoryComp>(TEXT("InventorySystemComp"));
	InventoryComp->SetIsReplicated(true);

	NetUpdateFrequency = 100.f;
}

void ABasePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
