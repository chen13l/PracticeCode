// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SubPoolOfUMG.generated.h"

class UBaseUMG;

DECLARE_LOG_CATEGORY_CLASS(SubPoolOfUMGLog, All, All);

UCLASS()
class DESIGNPATTERN_API USubPoolOfUMG : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<UBaseUMG> PrefabClass;
	UPROPERTY()
	TArray<UBaseUMG*> UseObjs;
	UPROPERTY()
	TArray<UBaseUMG*> UnUseObjs;

	UFUNCTION()
	UBaseUMG* Spawn(UWorld* World);
	UFUNCTION()
	void UnSpawn(UBaseUMG* UMG);
};
