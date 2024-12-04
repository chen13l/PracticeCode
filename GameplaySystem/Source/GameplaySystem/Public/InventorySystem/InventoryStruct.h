// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "Items/BaseItem.h"
#include "InventoryStruct.generated.h"

// for inventory 
USTRUCT(BlueprintType, Blueprintable)
struct FSlotStruct : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SlotStruct")
	FName ItemName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SlotStruct")
	int32 Nums = 0;
};

// for Item
USTRUCT(BlueprintType)
struct FItemStruct : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemStruct")
	FName ItemName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemStruct")
	FText Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemStruct")
	UTexture2D* Thumbnail;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemStruct")
	TSubclassOf<ABaseItem> ItemClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemStruct")
	int32 StackSize = 0;
};
