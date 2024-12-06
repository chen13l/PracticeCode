// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/UI/BaseInventoryWidget.h"
#include "InventorySystem/UI/BaseSlotWidget.h"
#include "Components/PanelWidget.h"
#include "Game/Player/BasePlayerState.h"
#include "InventorySystem/InventoryComp.h"

void UBaseInventoryWidget::InitWidgetToBox(TSubclassOf<UUserWidget> WidgetClass, int32 Nums, UPanelWidget* Outer)
{
	for (int32 i = 0; i < Nums; ++i)
	{
		UBaseSlotWidget* SlotWidget = CreateWidget<UBaseSlotWidget>(Outer, WidgetClass);
		USlotViewModel* NewSlotVM = InventoryViewModel->AddNewSlotVM(FName());
		SlotWidget->SetViewModel(NewSlotVM);
		Outer->AddChild(Cast<UWidget>(SlotWidget));
	}
}

void UBaseInventoryWidget::InitInventory()
{
	APlayerState* Src = GetOwningPlayerState();
	const ABasePlayerState* BasePlayerState = CastChecked<ABasePlayerState>(Src);
	if (BasePlayerState->GetInventoryComp())
	{
		InventoryViewModel = BasePlayerState->GetInventoryComp()->GetInventoryVM();
	}
}