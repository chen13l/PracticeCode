// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/UI/ViewModels/InventoryViewModel.h"

#include "FuncLib/HelperLib.h"
#include "InventorySystem/UI/ViewModels/SlotViewModel.h"

USlotViewModel* UInventoryViewModel::GetSlotVMByName(const FName& ItemName)
{
	for (auto& SlotVM : SlotVMArr)
	{
		if (SlotVM->GetSlotName() == ItemName) { return SlotVM; }
	}

	return AddNewSlotVM(ItemName);
}

USlotViewModel* UInventoryViewModel::AddNewSlotVM(const FName& SlotName)
{
	if (SlotVMArr.Num() < GetInventorySize())
	{
		USlotViewModel* NewSlotVM = NewObject<USlotViewModel>(this, SlotViewModelClass);
		FItemStruct ItemStruct = SlotName.IsNone()
			                         ? FItemStruct()
			                         : *UHelperLib::GetItemDataTable(this)->FindRow<FItemStruct>(SlotName, *SlotName.ToString());
		NewSlotVM->SetItemData(ItemStruct);
		SlotVMArr.Add(NewSlotVM);
		return NewSlotVM;
	}

	return nullptr;
}

bool UInventoryViewModel::RemoveSlotVMByName(const FName& SlotName)
{
	return false;
}
