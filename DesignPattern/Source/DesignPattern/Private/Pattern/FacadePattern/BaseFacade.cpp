// Fill out your copyright notice in the Description page of Project Settings.


#include "DesignPattern/Public/Pattern/FacadePattern/BaseFacade.h"

#include "DesignPattern/Public/Pattern/Managers/PoolBaseManager.h"
#include "Kismet/GameplayStatics.h"
#include "Pattern/Managers/MsgBaseManager.h"
#include "Pattern/Managers/StateManager.h"
#include "Pattern/Managers/UMGBaseManager.h"

UPoolBaseManager* UBaseFacade::GetPoolBaseManager(const UObject* WorldContextObject)
{
	return nullptr;
}

UMsgBaseManager* UBaseFacade::GetMsgBaseManager(const UObject* WorldContextObject)
{
	return UGameplayStatics::GetGameInstance(WorldContextObject)->GetSubsystem<UMsgBaseManager>();
}

UUMGBaseManager* UBaseFacade::GetUMGBaseManager(const UObject* WorldContextObject)
{
	return UGameplayStatics::GetGameInstance(WorldContextObject)->GetSubsystem<UUMGBaseManager>();
}

UStateManager* UBaseFacade::GetStateManager(const UObject* WorldContextObject)
{
	return UGameplayStatics::GetGameInstance(WorldContextObject)->GetSubsystem<UStateManager>();
}
