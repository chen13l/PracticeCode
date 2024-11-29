// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseUMG.generated.h"

class UBaseMsg;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class DESIGNPATTERN_API UBaseUMG : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="BaseUMG")
	int UMGIndex = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BsaeUMG")
	UBaseMsg* BaseMsg;

	UFUNCTION(BlueprintCallable, Category="BaseUMG")
	void SendMsg(UBaseMsg* Msg);

	//framework
	void OnCreateUMG(int Index = 0);
	void OnShowUMG();
	void OnHideUMG();
	void OnDestroyUMG();

	virtual void OnBindLocalEvent();
	virtual void OnUnBindLocalEvent();

	UFUNCTION(BlueprintNativeEvent, Category="BaseUMG")
	void OnCreate();
	UFUNCTION(BlueprintNativeEvent, Category="BaseUMG")
	void OnShow();
	UFUNCTION(BlueprintNativeEvent, Category="BaseUMG")
	void OnHide();
	UFUNCTION(BlueprintNativeEvent, Category="BaseUMG")
	void OnDestroy();
};
