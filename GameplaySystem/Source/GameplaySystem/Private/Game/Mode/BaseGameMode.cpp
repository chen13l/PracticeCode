// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySystem/Public/Game/Mode/BaseGameMode.h"

#include "Engine/DataTable.h"

UDataTable* ABaseGameMode::GetItemDataTable() const
{
	return ItemDataTable;
}
