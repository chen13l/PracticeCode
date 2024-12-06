// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "InventorySystem/UI/BaseSlotWidget.h"
#include "BaseUMGManager.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FSlotArrStruct
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<UBaseSlotWidget*> SlotsArr;
};

UCLASS()
class GAMEPLAYSYSTEM_API UBaseUMGManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Inventory")
	TMap<TSubclassOf<UBaseSlotWidget>, FSlotArrStruct> SlotType_SlotsMap;
};
