// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySystem/Public/FuncLib/HelperLib.h"

#include "Game/Mode/BaseGameMode.h"
#include "Kismet/GameplayStatics.h"

UDataTable* UHelperLib::GetItemDataTable(const UObject* WorldContextObject)
{
	ABaseGameMode* BaseGameMode = Cast<ABaseGameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
	return BaseGameMode->GetItemDataTable();
}
