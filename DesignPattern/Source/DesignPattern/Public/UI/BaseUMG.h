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
	int Index = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BsaeUMG")
	UBaseMsg* BaseMsg;

	UFUNCTION(BlueprintCallable, Category="BaseUMG")
	void SendMsg(UBaseMsg* Msg);
};
