// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStruct.h"
#include "Components/ActorComponent.h"
#include "Game/Player/BasePlayerState.h"
#include "InventoryComp.generated.h"


class ABasePlayerState;
class AGameplaySystemCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAMEPLAYSYSTEM_API UInventoryComp : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComp();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Interaction
	UFUNCTION(BlueprintCallable, Category="InventoryInteraction")
	AActor* InteractiveTrace();
	// ~End Interaction

	// Interaction
	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	void Pick();
	// ~End Interaction

	// private properties
	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	FORCEINLINE int32 GetInventorySize() const { return InventorySize; }

	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	FORCEINLINE void SetInventorySize(int32 NewSize) { InventorySize = NewSize; }

	FORCEINLINE void SetOwnPlayerState(ABasePlayerState* InState) { OwnPlayerState = InState; }
	FORCEINLINE void SetOwnPlayerCharacter(AGameplaySystemCharacter* InCharacter) { OwnCharacter = InCharacter; }
	// ~End private properties

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const TArray<FSlotStruct>& GetContent() { return Content; }

protected:
	virtual void BeginPlay() override;

	// Data
	UPROPERTY(Replicated)
	TArray<FSlotStruct> Content;
	UPROPERTY(EditDefaultsOnly, Category="InventoryComp")
	TObjectPtr<UDataTable> ItemDataTable;


	UFUNCTION(BlueprintCallable, BlueprintPure, Category="InventoryComp")
	int32 GetItemIndexByName(const FName& ItemName) const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="InventoryComp")
	int32 FindEmptySlot() const;
	// ~End Data

	// Interaction
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InventoryInteraction")
	float InteractionRange = 300.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InventoryInteraction")
	float TraceSphereRadius = 10.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InventoryInteraction")
	TArray<AActor*> IgnoreActors;

	UPROPERTY()
	TObjectPtr<AActor> CurrentTraceActor;
	UPROPERTY()
	TObjectPtr<AActor> LastTraceActor;

	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	void AddToInventory(int32 Quantity, const FName& ItemName);
	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	void RemoveFormInventory();
	// ~End Interaction

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory", meta=(AllowPrivateAccess))
	int32 InventorySize = 16;

	UPROPERTY()
	AGameplaySystemCharacter* OwnCharacter;
	UPROPERTY()
	ABasePlayerState* OwnPlayerState;
};
