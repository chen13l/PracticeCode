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

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	FORCEINLINE int32 GetInventorySize() const { return InventorySize; }

	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	FORCEINLINE void SetInventorySize(int32 NewSize) { InventorySize = NewSize; }

	// Interaction
	UFUNCTION(BlueprintCallable, Category="InventoryInteraction")
	AActor* InteractiveTrace();
	// ~End Interaction
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(Replicated)
	TArray<FSlotStruct> Content;

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
	// ~End Interaction 

public:
	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	void AddToInventory();
	UFUNCTION(BlueprintCallable, Category="InventoryComp")
	void RemoveFormInventory();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory", meta=(AllowPrivateAccess))
	int32 InventorySize = 16;
};
