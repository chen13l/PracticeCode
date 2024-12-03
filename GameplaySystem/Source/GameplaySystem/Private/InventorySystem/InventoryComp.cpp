// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySystem/Public/InventorySystem/InventoryComp.h"

#include "Net/UnrealNetwork.h"


UInventoryComp::UInventoryComp()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UInventoryComp::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION(UInventoryComp, Content, COND_OwnerOnly);
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UInventoryComp::AddToInventory()
{
}

void UInventoryComp::RemoveFormInventory()
{
}
