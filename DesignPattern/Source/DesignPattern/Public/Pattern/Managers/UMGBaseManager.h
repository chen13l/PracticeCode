// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseManager.h"
#include "UMGBaseManager.generated.h"

/**
 * 
 */
DECLARE_LOG_CATEGORY_CLASS(UMGBaseManagerLog, All, All);

class UBaseUMG;

USTRUCT(BlueprintType)
struct FUMGArrayStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UBaseUMG*> UMGs;
};

UCLASS(BlueprintType)
class DESIGNPATTERN_API UUMGBaseManager : public UBaseManager
{
	GENERATED_BODY()

public:
	UUMGBaseManager();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY()
	TMap<FString, FUMGArrayStruct> Str_UMGMap;
	UPROPERTY()
	TMap<FString, int> UMGCountMap;

	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	UBaseUMG* GetUMG(TSubclassOf<UBaseUMG> UMGClass, int UMGIndex = -1, bool CanLast = true);
	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	UBaseUMG* CreateUMG(TSubclassOf<UBaseUMG> UMGClass, bool FromPool = true);
	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	UBaseUMG* ShowUMGByClass(TSubclassOf<UBaseUMG> UMGClass, int UMGIndex = -1, int ZOrder = 0, bool AutoCreate = true);
	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	UBaseUMG* ShowUMG(UBaseUMG* UMG, int ZOrder = 0);
	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	bool HideUMGByClass(TSubclassOf<UBaseUMG> UMGClass, int UMGIndex = -1);
	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	bool HideUMG(UBaseUMG* UMG);
	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	void HideAllUMG();
	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	bool DestroyUMGByClass(TSubclassOf<UBaseUMG> UMGClass, int UMGIndex = -1);
	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	bool DestroyUMG(UBaseUMG* UMG);
	UFUNCTION(BlueprintCallable, Category="UMGBaseManager")
	void DestroyAllUMG();
};
