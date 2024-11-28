// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseState.generated.h"

class UBaseMsg;
enum class EMsgType : uint8;

UCLASS()
class DESIGNPATTERN_API ABaseState : public AActor
{
	GENERATED_BODY()

public:
	ABaseState();

protected:
	virtual void BeginPlay() override;

public:
	/*virtual void Tick(float DeltaTime) override;*/
	UFUNCTION(BlueprintNativeEvent)
	FString GetStateName();
	
	void OnCreateState();
	void OnEnterState();
	void OnExitState();
	void OnLevelChangeState();

	UFUNCTION(BlueprintNativeEvent, Category="BaseState")
	void OnStateConstruction();
	UFUNCTION(BlueprintNativeEvent, Category="BaseState")
	void OnTestEnter();
	UFUNCTION(BlueprintNativeEvent, Category="BaseState")
	void OnEnter();
	UFUNCTION(BlueprintNativeEvent, Category="BaseState")
	void OnLevelChange();
	UFUNCTION(BlueprintNativeEvent, Category="BaseState")
	void OnExit();

	UFUNCTION(BlueprintCallable, Category="BaseState")
	bool IsCurrentState();
	UFUNCTION(BlueprintCallable, Category="BaseState")
	void EnterState(TSubclassOf<ABaseState> StateClass);

	// Msg
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="BaseState")
	TArray<EMsgType> DynamicMsgTypes;

	UFUNCTION(BlueprintCallable,Category="BaseState")
	void BindDynamicMsg();
	UFUNCTION(BlueprintCallable,Category="BaseState")
	void UnBindDynamicMsg();

	UFUNCTION(BlueprintNativeEvent,Category="BaseState")
	void ExecuteMsg(UBaseMsg* Msg);

	UFUNCTION(BlueprintNativeEvent,Category="BaseState")
	void SetDynamicMsg();

	void ExecuteStateMsg(UBaseMsg* Msg);
	// ~Msg
};
