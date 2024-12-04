// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplaySystem/Public/InventorySystem/Items/BaseItem.h"

#include "InventorySystem/Items/ItemDataComp.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	ItemDataComp = CreateDefaultSubobject<UItemDataComp>(TEXT("ItemDataComp"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseItem::Picked_Implementation()
{
	IItemInteraction::Picked_Implementation();
	if (HasAuthority())
	{
		Destroy();
	}
}

FName ABaseItem::GetItemName_Implementation()
{
	if(ItemDataComp == nullptr) {return FName();}
	return ItemDataComp->GetItemName();
}

