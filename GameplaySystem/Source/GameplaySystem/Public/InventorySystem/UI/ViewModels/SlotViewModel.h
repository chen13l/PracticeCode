// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "InventorySystem/InventoryStruct.h"
#include "SlotViewModel.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemChangeSignature,FItemStruct,ItemData);

UCLASS()
class GAMEPLAYSYSTEM_API USlotViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess))
	int32 Quantity;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FItemStruct ItemData;

public:
	UPROPERTY(BlueprintAssignable)
	FItemChangeSignature ItemChangeDelegate;
	
	// call
	void SetItemData(const FItemStruct& NewData);
	void SetQuantity(int32 NewQuantity);
	// ~
	
	FName GetSlotName() const;

	int32 GetQuantity() const;

	UFUNCTION(BlueprintPure,FieldNotify)
	float GetOpacity()const;
	
};
