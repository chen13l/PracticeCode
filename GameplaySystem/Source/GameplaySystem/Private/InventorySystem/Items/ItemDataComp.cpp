// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/Items/ItemDataComp.h"

UItemDataComp::UItemDataComp()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FName UItemDataComp::GetItemName() const
{
	const FItemStruct* ItemStruct = ItemData.GetRow<FItemStruct>("");
	return ItemStruct != nullptr ? ItemStruct->ItemName : FName();
}

void UItemDataComp::BeginPlay()
{
	Super::BeginPlay();
	
}

