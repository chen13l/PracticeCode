// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ViewModels/SlotViewModel.h"
#include "BaseSlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYSYSTEM_API UBaseSlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Inventory|SlotVM")
	FORCEINLINE void SetViewModel(USlotViewModel* NewSlotViewModel) { SlotViewModel = NewSlotViewModel; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Inventory|SlotVM")
	FORCEINLINE USlotViewModel* GetSlotViewModel() const { return SlotViewModel; }

protected:
	UPROPERTY(BlueprintReadWrite, Category="Inventory|SlotVM")
	USlotViewModel* SlotViewModel;
};
