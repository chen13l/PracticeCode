// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/UI/MainHUD.h"
#include "InventorySystem/UI/BaseInventoryWidget.h"

#include "Blueprint/UserWidget.h"

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	if (InventoryWidgetClass)
	{
		InventoryWidget = CreateWidget<UBaseInventoryWidget>(GetOwningPlayerController(), InventoryWidgetClass);
		InventoryWidget->InitWidget();
		InventoryWidget->AddToViewport();
		InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}
