// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStruct.h"
#include "Components/ActorComponent.h"
#include "InventoryComp.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAMEPLAYSYSTEM_API UInventoryComp : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComp();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	FORCEINLINE int32 GetInventorySize() const { return InventorySize; }
	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	FORCEINLINE void SetInventorySize(int32 NewSize) {InventorySize = NewSize;}

protected:
	virtual void BeginPlay() override;

	UPROPERTY(Replicated)
	TArray<FSlotStruct> Content;

public:
	UFUNCTION(BlueprintCallable)
	void AddToInventory();
	UFUNCTION(BlueprintCallable)
	void RemoveFormInventory();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory", meta=(AllowPrivateAccess))
	int32 InventorySize = 16;
};
