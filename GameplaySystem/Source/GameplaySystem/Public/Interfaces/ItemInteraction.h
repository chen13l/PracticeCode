// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInteraction.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UItemInteraction : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEPLAYSYSTEM_API IItemInteraction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Picked();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FName GetItemName();
};
