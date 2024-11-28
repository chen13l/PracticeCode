// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BaseFacade.generated.h"

class UStateManager;
class UUMGBaseManager;
class UMsgBaseManager;
class UPoolBaseManager;
/**
 * 
 */
UCLASS()
class DESIGNPATTERN_API UBaseFacade : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="BaseFacade", meta=(DefaultToSelf="WorldContextObject"))
	static UPoolBaseManager* GetPoolBaseManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="BaseFacade", meta=(DefaultToSelf="WorldContextObject"))
	static UMsgBaseManager* GetMsgBaseManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="BaseFacade", meta=(DefaultToSelf="WorldContextObject"))
	static UUMGBaseManager* GetUMGBaseManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="BaseFacade", meta=(DefaultToSelf="WorldContextObject"))
	static UStateManager* GetStateManager(const UObject* WorldContextObject);

};
