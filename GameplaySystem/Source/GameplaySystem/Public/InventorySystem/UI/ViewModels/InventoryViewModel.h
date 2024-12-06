// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "InventoryViewModel.generated.h"

class USlotViewModel;
/**
 * 
 */
UCLASS()
class GAMEPLAYSYSTEM_API UInventoryViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	USlotViewModel* GetSlotVMByName(const FName& ItemName);

	UPROPERTY(EditDefaultsOnly, Category="Sub Model")
	TSubclassOf<USlotViewModel> SlotViewModelClass;

	UPROPERTY(BlueprintReadOnly, Category="Sub Model")
	TObjectPtr<USlotViewModel> SlotViewModel;

	int32 GetSlotArrSize()const{return SlotVMArr.Num();}
private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess))
	TArray<USlotViewModel*> SlotVMArr;

	int32 InventorySize;

public:
	FORCEINLINE void SetInventorySize(const int32& NewSize) { InventorySize = NewSize; }
	FORCEINLINE int32 GetInventorySize() const { return InventorySize; }

	UFUNCTION(BlueprintCallable, Category="InventoryVM")
	USlotViewModel* AddNewSlotVM(const FName& SlotName);
	UFUNCTION(BlueprintCallable, Category="InventoryVM")
	bool RemoveSlotVMByName(const FName& SlotName);
};
