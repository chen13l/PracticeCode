// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseManager.h"
#include "Pattern/ObserverMode/BaseMsg.h"
#include "Pattern/StatePattern/BaseState.h"
#include "MsgBaseManager.generated.h"

/**
 * 
 */
DECLARE_LOG_CATEGORY_CLASS(MsgBaseManagerLog, All, All);

USTRUCT(BlueprintType)
struct FStatesArray
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<ABaseState*> States;
};

UCLASS()
class DESIGNPATTERN_API UMsgBaseManager : public UBaseManager
{
	GENERATED_BODY()

public:
	UMsgBaseManager();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<EMsgType, FStatesArray> Msg_StatesMap;

	UFUNCTION(BlueprintCallable, Category="MsgBaseManager")
	void ExecuteMsg(UBaseMsg* Msg);

	UFUNCTION(BlueprintCallable, Category="MsgBaseManager")
	void RegisterState(const EMsgType& MsgType, ABaseState* State);

	UFUNCTION(BlueprintCallable, Category="MsgBaseManager")
	void UnRegisterState(const EMsgType& MsgType, ABaseState* State);
};
