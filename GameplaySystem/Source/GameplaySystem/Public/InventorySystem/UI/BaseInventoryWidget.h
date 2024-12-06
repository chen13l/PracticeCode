// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ViewModels/InventoryViewModel.h"
#include "BaseInventoryWidget.generated.h"

class UBaseSlotWidget;
/**
 * 
 */
UCLASS()
class GAMEPLAYSYSTEM_API UBaseInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitWidgetToBox(TSubclassOf<UUserWidget> WidgetClass, int32 Nums, UPanelWidget* Outer);

	UFUNCTION(BlueprintCallable)
	void InitInventory();

	UFUNCTION(BlueprintImplementableEvent)
	void InitWidget();

	// ViewModel
	UFUNCTION(BlueprintCallable, Category="Inventory|VM")
	FORCEINLINE void SetViewModel(UInventoryViewModel* NewVM) { InventoryViewModel = NewVM; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Inventory|VM")
	FORCEINLINE UInventoryViewModel* GetInventoryVM() const { return InventoryViewModel; }

	// ~End ViewModel
protected:
	UPROPERTY(BlueprintReadWrite, Category="Inventory|VM")
	TObjectPtr<UInventoryViewModel> InventoryViewModel;
};
