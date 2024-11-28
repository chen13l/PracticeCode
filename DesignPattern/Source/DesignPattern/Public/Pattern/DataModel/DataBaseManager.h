// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataBaseManager.generated.h"

class UBaseDataModel;
/**
 * 
 */
DECLARE_LOG_CATEGORY_CLASS(DataBaseManagerLog, All, All);

UCLASS()
class DESIGNPATTERN_API UDataBaseManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UDataBaseManager();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	UPROPERTY(BlueprintReadWrite)
	UBaseDataModel* BaseDataModel;

};
