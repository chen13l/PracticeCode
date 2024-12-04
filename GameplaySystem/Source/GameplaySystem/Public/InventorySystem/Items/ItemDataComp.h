// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventorySystem/InventoryStruct.h"
#include "ItemDataComp.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAMEPLAYSYSTEM_API UItemDataComp : public UActorComponent
{
	GENERATED_BODY()

public:
	UItemDataComp();

	// Data
	FName GetItemName() const;
	// ~Data
	
protected:
	virtual void BeginPlay() override;
	
	// Data
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemData")
	FDataTableRowHandle ItemData;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemData")
	int32 Quantity = 1;
	// ~Data
};
