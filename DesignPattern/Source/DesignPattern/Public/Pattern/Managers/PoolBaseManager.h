// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseManager.h"
#include "PoolBaseManager.generated.h"

class UBaseUMG;
class USubPoolOfUMG;
DECLARE_LOG_CATEGORY_CLASS(PoolBaseManagerLog, All, All);

UCLASS()
class DESIGNPATTERN_API UPoolBaseManager : public UBaseManager
{
	GENERATED_BODY()

public:
	UPoolBaseManager();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	UPROPERTY()
	TMap<FString,USubPoolOfUMG*> UMGPools;
	UFUNCTION()
	UBaseUMG* SpawnUMG(TSubclassOf<UBaseUMG> UMGClass);
	UFUNCTION()
	void UnSpawnUMG(UBaseUMG* UMG);
	UFUNCTION()
	void ClearUMGPool(bool force = false);
	
};
