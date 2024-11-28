// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseDataModel.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERN_API UBaseDataModel : public UObject
{
	GENERATED_BODY()

public:
	UBaseDataModel();
	
	UPROPERTY(BlueprintReadWrite)
	FName Name = "DataModel";
};
