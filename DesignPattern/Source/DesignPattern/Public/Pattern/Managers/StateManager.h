// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseManager.h"
#include "Pattern/DataModel/DataBaseManager.h"
#include "Pattern/StatePattern/BaseState.h"
#include "StateManager.generated.h"

/**
 * 
 */
DECLARE_LOG_CATEGORY_CLASS(StateManagerLog, All, All);

UCLASS()
class DESIGNPATTERN_API UStateManager : public UDataBaseManager
{
	GENERATED_BODY()

public:
	UStateManager();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY()
	TMap<TSubclassOf<ABaseState>, ABaseState*> StatesMap;

	UPROPERTY()
	ABaseState* CurrentState;

public:
	UFUNCTION(BlueprintCallable, Category="StateManager")
	void EnterState(TSubclassOf<ABaseState> StateClass);

	UFUNCTION(BlueprintCallable, Category="StateManager")
	ABaseState* GetState(TSubclassOf<ABaseState> StateClass);

	UFUNCTION(BlueprintCallable, Category="StateManager")
	ABaseState* GetCurrentState();

private:
	
};
