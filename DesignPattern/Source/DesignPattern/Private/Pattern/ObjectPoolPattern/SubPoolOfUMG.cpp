// Fill out your copyright notice in the Description page of Project Settings.


#include "Pattern/ObjectPoolPattern/SubPoolOfUMG.h"

#include "UI/BaseUMG.h"

UBaseUMG* USubPoolOfUMG::Spawn(UWorld* World)
{
	UBaseUMG* UMG = nullptr;

	int32 NumCanUse = UnUseObjs.Num();
	if (NumCanUse > 0)
	{
		UMG = UnUseObjs[NumCanUse - 1];
		UnUseObjs.RemoveAt(NumCanUse - 1);
		UseObjs.Add(UMG);
		UE_LOG(SubPoolOfUMGLog, Warning, TEXT("Get from unuse list %s"), *UMG->GetClass()->GetName());
	}
	if (UMG == nullptr)
	{
		UMG = CreateWidget<UBaseUMG>(World, PrefabClass);
		if (UMG == nullptr) { UE_LOG(SubPoolOfUMGLog, Warning, TEXT("umg create failed by ObjectPool")); }

		UseObjs.Add(UMG);
		UE_LOG(SubPoolOfUMGLog, Warning, TEXT("Get from create %s"), *UMG->GetClass()->GetName());
	}
	return UMG;
}

void USubPoolOfUMG::UnSpawn(UBaseUMG* UMG)
{
	if (UMG != nullptr && UseObjs.Contains(UMG))
	{
		UseObjs.Remove(UMG);
		UnUseObjs.Add(UMG);
		if (UMG->IsInViewport())
		{
			UMG->RemoveFromParent();
		}
		UE_LOG(SubPoolOfUMGLog, Warning, TEXT("UnSpawn %s"), *UMG->GetClass()->GetName());
	}
}
