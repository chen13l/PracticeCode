// Fill out your copyright notice in the Description page of Project Settings.


#include "Pattern/DataModel/DataBaseManager.h"

#include "Pattern/DataModel/BaseDataModel.h"

UDataBaseManager::UDataBaseManager()
{
}

void UDataBaseManager::Initialize(FSubsystemCollectionBase& Collection)
{
	if (!IsValid(BaseDataModel))
	{
		BaseDataModel = NewObject<UBaseDataModel>(this);
	}
	UE_LOG(DataBaseManagerLog, Warning, TEXT("DataBaseManager Initialize"));

	Super::Initialize(Collection);
}
