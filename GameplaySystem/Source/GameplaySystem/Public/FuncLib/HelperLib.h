// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HelperLib.generated.h"

class UDataTable;
/**
 * 
 */
UCLASS()
class GAMEPLAYSYSTEM_API UHelperLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Inventory|Data",meta=(DefaultToSelf="WorldContextObject"))
	static UDataTable* GetItemDataTable(const UObject* WorldContextObject);
};
