// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/UI/ViewModels/SlotViewModel.h"

void USlotViewModel::SetQuantity(int32 NewQuantity)
{
	UE_MVVM_SET_PROPERTY_VALUE(Quantity, NewQuantity);
}

int32 USlotViewModel::GetQuantity() const
{
	return Quantity;
}

float USlotViewModel::GetOpacity() const
{
	if(GetQuantity() <= 0)
	{
		return 0;
	}
	return 1;
}

void USlotViewModel::SetItemData(const FItemStruct& NewData)
{
	ItemData = NewData;
	ItemChangeDelegate.Broadcast(ItemData);
	SetQuantity(0);
}

FName USlotViewModel::GetSlotName() const
{
	return ItemData.ItemName;
}
