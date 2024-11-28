// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseMsg.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EMsgType :uint8
{
	M_Default,
	M_Test,
	M_Server,
	M_UMG,
	M_Actor,
	M_WS_Response, //websocket response
	M_SenToUMG,
	M_Error_Msg,
	Max
};

UCLASS(Blueprintable, BlueprintType)
class DESIGNPATTERN_API UBaseMsg : public UObject
{
	GENERATED_BODY()

public:
	UBaseMsg();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Msg")
	EMsgType MsgType = EMsgType::M_Default;
};
