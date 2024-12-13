﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BaseGameMode.generated.h"

class UDataTable;
/**
 * 
 */
UCLASS()
class GAMEPLAYSYSTEM_API ABaseGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	UDataTable* GetItemDataTable()const ;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	UDataTable* ItemDataTable;
};
