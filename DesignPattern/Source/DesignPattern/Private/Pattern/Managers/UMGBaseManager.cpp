// Fill out your copyright notice in the Description page of Project Settings.


#include "DesignPattern/Public/Pattern/Managers/UMGBaseManager.h"

#include "UI/BaseUMG.h"

UUMGBaseManager::UUMGBaseManager()
{
}

void UUMGBaseManager::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(UMGBaseManagerLog, Warning, TEXT("UMGBaseManager Initialize"));
	Super::Initialize(Collection);
}

UBaseUMG* UUMGBaseManager::GetUMG(TSubclassOf<UBaseUMG> UMGClass, int UMGIndex, bool CanLast)
{
	const FString UMGName = UMGClass.Get()->GetName();
	if (!Str_UMGMap.Contains(UMGName)) { return nullptr; }

	TArray<UBaseUMG*> UMGArr = Str_UMGMap.FindRef(UMGName).UMGs;
	if (UMGArr.Num() <= 0) { return nullptr; }

	// 通过Index找UMG，若得到UMG为nullptr，CanLast时获取Arr最后一个UMG
	UBaseUMG* OutUMG = nullptr;
	for (const auto& UMG : UMGArr)
	{
		if (UMG->UMGIndex == UMGIndex)
		{
			OutUMG = UMG;
			break;
		}
	}

	if (OutUMG == nullptr && CanLast)
	{
		OutUMG = UMGArr[UMGArr.Num() - 1];
	}
	return OutUMG;
}

UBaseUMG* UUMGBaseManager::CreateUMG(TSubclassOf<UBaseUMG> UMGClass)
{
	const FString UMGName = UMGClass.Get()->GetName();

	//创建UMG
	UBaseUMG* NewUMG = CreateWidget<UBaseUMG>(GetWorld(), UMGClass);

	if (NewUMG == nullptr) { return nullptr; }
	// 在UMGIndex中设置Count
	// Str_UMGMap中未找到同类UMG
	if (!Str_UMGMap.Contains(UMGName))
	{
		// 若该类记录中不为0则置0，无记录则创建
		if (UMGCountMap.Contains(UMGName)) { UMGCountMap[UMGName] = 0; }
		else { UMGCountMap.Add(UMGName, 0); }

		// 记录该类UMG
		FUMGArrayStruct UMGArrStruct;
		Str_UMGMap.Add(UMGName, UMGArrStruct);
	}
	else
	{
		UMGCountMap[UMGName] = UMGCountMap[UMGName] + 1;
	}

	NewUMG->OnCreateUMG(UMGCountMap[UMGName]);
	// UMG列表中加入新建UMG
	Str_UMGMap[UMGName].UMGs.Add(NewUMG);

	return NewUMG;
}

UBaseUMG* UUMGBaseManager::ShowUMGByClass(TSubclassOf<UBaseUMG> UMGClass, int UMGIndex, int ZOrder, bool AutoCreate)
{
	UBaseUMG* UMG = GetUMG(UMGClass, UMGIndex, false);
	if (UMG == nullptr)
	{
		if (AutoCreate) { UMG = CreateUMG(UMGClass); }
		else { return nullptr; }
	}
	if (!UMG->IsInViewport()) { UMG->AddToViewport(ZOrder); }

	UMG->OnShowUMG();
	return UMG;
}

UBaseUMG* UUMGBaseManager::ShowUMG(UBaseUMG* UMG, int ZOrder)
{
	if (UMG == nullptr) { return nullptr; }
	if (!UMG->IsInViewport()) { UMG->AddToViewport(ZOrder); }

	UMG->OnShowUMG();
	return UMG;
}

bool UUMGBaseManager::HideUMGByClass(TSubclassOf<UBaseUMG> UMGClass, int UMGIndex)
{
	UBaseUMG* UMG = GetUMG(UMGClass, UMGIndex, false);
	return HideUMG(UMG);
}

bool UUMGBaseManager::HideUMG(UBaseUMG* UMG)
{
	if (UMG != nullptr)
	{
		if (UMG->IsInViewport())
		{
			UMG->RemoveFromParent();
			UMG->OnHideUMG();
			return true;
		}
		UE_LOG(UMGBaseManagerLog, Warning, TEXT("UMG isn't in viewport"));
	}
	return false;
}

void UUMGBaseManager::HideAllUMG()
{
	for (auto& [UMGClassName,UMGsArrStruct] : Str_UMGMap)
	{
		for(auto& UMG : UMGsArrStruct.UMGs)
		{
			HideUMG(UMG);
		}
	}
}

bool UUMGBaseManager::DestroyUMGByClass(TSubclassOf<UBaseUMG> UMGClass, int UMGIndex)
{
	UBaseUMG* UMG = GetUMG(UMGClass, UMGIndex, false);
	return DestroyUMG(UMG);
}

bool UUMGBaseManager::DestroyUMG(UBaseUMG* UMG)
{
	if (UMG != nullptr)
	{
		FString UMGClassName = UMG->GetClass()->GetName();
		if (!Str_UMGMap.Contains(UMGClassName)) { return false; }
		HideUMG(UMG);

		UMG->OnDestroyUMG();
		Str_UMGMap[UMGClassName].UMGs.Remove(UMG);
		if (Str_UMGMap[UMGClassName].UMGs.Num() <= 0) { Str_UMGMap.Remove(UMGClassName); }

		UMG->BeginDestroy();
	}
	
	return true;
}

void UUMGBaseManager::DestroyAllUMG()
{
	HideAllUMG();
	for (auto& [UMGClassName,UMGsArrStruct] : Str_UMGMap)
	{
		for(auto& UMG : UMGsArrStruct.UMGs)
		{
			UMG->OnDestroyUMG();
			UMG->BeginDestroy();
		}
	}
	Str_UMGMap.Empty();
}
