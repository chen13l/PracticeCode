// Fill out your copyright notice in the Description page of Project Settings.


#include "Pattern/StatePattern/BaseState.h"

#include "Pattern/FacadePattern/BaseFacade.h"
#include "Pattern/Managers/MsgBaseManager.h"
#include "Pattern/Managers/StateManager.h"


ABaseState::ABaseState()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseState::BeginPlay()
{
	Super::BeginPlay();
}

FString ABaseState::GetStateName_Implementation()
{
	return FString();
}


void ABaseState::OnCreateState()
{
	OnStateConstruction();
}

void ABaseState::OnEnterState()
{
	BindDynamicMsg();
	OnTestEnter();
	OnEnter();
}

void ABaseState::OnExitState()
{
	UnBindDynamicMsg();
	OnExit();
}

void ABaseState::OnLevelChangeState()
{
	OnLevelChange();
}

void ABaseState::OnStateConstruction_Implementation()
{
}

void ABaseState::OnTestEnter_Implementation()
{
}

void ABaseState::OnEnter_Implementation()
{
}

void ABaseState::OnLevelChange_Implementation()
{
}

void ABaseState::OnExit_Implementation()
{
}

bool ABaseState::IsCurrentState()
{
	return UBaseFacade::GetStateManager(this)->CurrentState == this;
}

void ABaseState::EnterState(TSubclassOf<ABaseState> StateClass)
{
	UBaseFacade::GetStateManager(this)->EnterState(StateClass);
}

void ABaseState::BindDynamicMsg()
{
	SetDynamicMsg();
	for (auto& MsgType : DynamicMsgTypes)
	{
		UBaseFacade::GetMsgBaseManager(this)->RegisterState(MsgType, this);
	}
}

void ABaseState::UnBindDynamicMsg()
{
	for (auto& MsgType : DynamicMsgTypes)
	{
		UBaseFacade::GetMsgBaseManager(this)->UnRegisterState(MsgType, this);
	}
}

void ABaseState::ExecuteMsg_Implementation(UBaseMsg* Msg)
{
}

void ABaseState::SetDynamicMsg_Implementation()
{
}

void ABaseState::ExecuteStateMsg(UBaseMsg* Msg)
{
	ExecuteMsg(Msg);
}
