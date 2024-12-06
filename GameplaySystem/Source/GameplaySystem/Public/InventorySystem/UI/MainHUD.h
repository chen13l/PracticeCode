// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

class UBaseInventoryWidget;
class UInventoryViewModel;
/**
 * 
 */
UCLASS()
class GAMEPLAYSYSTEM_API AMainHUD : public AHUD
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="Inventory")
	FORCEINLINE UBaseInventoryWidget* GetInventoryWidget()const{return InventoryWidget;}

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	TSubclassOf<UUserWidget> InventoryWidgetClass;
	UPROPERTY(BlueprintReadOnly, Category="Inventory")
	TObjectPtr<UBaseInventoryWidget> InventoryWidget;
};
