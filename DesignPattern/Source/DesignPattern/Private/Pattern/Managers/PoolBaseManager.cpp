// Fill out your copyright notice in the Description page of Project Settings.


#include "DesignPattern/Public/Pattern/Managers/PoolBaseManager.h"

#include "Pattern/ObjectPoolPattern/SubPoolOfUMG.h"
#include "UI/BaseUMG.h"

UPoolBaseManager::UPoolBaseManager()
{
}

void UPoolBaseManager::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(PoolBaseManagerLog, Warning, TEXT("PoolBaseManager Initialize"));
	Super::Initialize(Collection);
}

UBaseUMG* UPoolBaseManager::SpawnUMG(TSubclassOf<UBaseUMG> UMGClass)
{
	FString UMGName = UMGClass.Get()->GetName();
	USubPoolOfUMG* SubPool = nullptr;
	if (!UMGPools.Contains(UMGName))
	{
		SubPool = NewObject<USubPoolOfUMG>();
		SubPool->PrefabClass = UMGClass;
		UMGPools.Add(UMGName, SubPool);
	}
	else
	{
		SubPool = UMGPools[UMGName];
	}
	return SubPool->Spawn(GetWorld());
}

void UPoolBaseManager::UnSpawnUMG(UBaseUMG* UMG)
{
	FString UMGName = UMG->GetName();
	if (UMGPools.Contains(UMGName))
	{
		UMGPools[UMGName]->UnSpawn(UMG);
	}
}

void UPoolBaseManager::ClearUMGPool(bool force)
{
	for (auto& [ClassName,SubPool] : UMGPools)
	{
		SubPool->UnUseObjs.Empty();
		if (force)
		{
			if (SubPool->UseObjs.Num() > 0)
			{
				UE_LOG(PoolBaseManagerLog, Warning, TEXT("UMG pool clear, but [%s] useObjs is not empty, count %d"),
					*ClassName,SubPool->UseObjs.Num());
			}
			SubPool->UseObjs.Empty();
		}
	}
	UMGPools.Empty();
}
