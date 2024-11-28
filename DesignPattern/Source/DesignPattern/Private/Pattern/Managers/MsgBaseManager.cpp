// Fill out your copyright notice in the Description page of Project Settings.


#include "DesignPattern/Public/Pattern/Managers/MsgBaseManager.h"

UMsgBaseManager::UMsgBaseManager()
{
}

void UMsgBaseManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UMsgBaseManager::Deinitialize()
{
	Super::Deinitialize();
}

void UMsgBaseManager::ExecuteMsg(UBaseMsg* Msg)
{
	if (Msg == nullptr) { return; }
	EMsgType MsgType = Msg->MsgType;
	if (Msg_StatesMap.Contains(MsgType))
	{
		TArray<ABaseState*> StatesArr = Msg_StatesMap.FindRef(MsgType).States;
		for (auto& State : StatesArr)
		{
			if (State == nullptr) { UE_LOG(MsgBaseManagerLog, Warning, TEXT("Execute state failed,state is nullptr")); }
			else
			{
				//TODO: ExecutingState
				State->ExecuteMsg(Msg);
			}
		}
	}
}

void UMsgBaseManager::RegisterState(const EMsgType& MsgType, ABaseState* State)
{
	if (State != nullptr)
	{
		if (!Msg_StatesMap.Contains(MsgType))
		{
			FStatesArray StatesArr;
			Msg_StatesMap.Add(MsgType, StatesArr);
		}
		if (!Msg_StatesMap[MsgType].States.Contains(State))
		{
			Msg_StatesMap[MsgType].States.Add(State);
			UE_LOG(MsgBaseManagerLog, Warning, TEXT("Register state"));
		}
	}
	else { UE_LOG(MsgBaseManagerLog, Error, TEXT("Register state failed")); }
}

void UMsgBaseManager::UnRegisterState(const EMsgType& MsgType, ABaseState* State)
{
	if (Msg_StatesMap.Contains(MsgType))
	{
		if (Msg_StatesMap[MsgType].States.Contains(State))
		{
			Msg_StatesMap[MsgType].States.Remove(State);
			if (Msg_StatesMap[MsgType].States.Num() <= 0) { Msg_StatesMap.Remove(MsgType); }
		}
	}
}
