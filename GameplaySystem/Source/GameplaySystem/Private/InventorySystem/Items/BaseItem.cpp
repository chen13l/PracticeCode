// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplaySystem/Public/InventorySystem/Items/BaseItem.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

