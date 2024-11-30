// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseUMG.h"

#include "Pattern/FacadePattern/BaseFacade.h"
#include "Pattern/Managers/MsgBaseManager.h"
#include "Pattern/ObserverMode/BaseMsg.h"

void UBaseUMG::NativeConstruct()
{
	if (!IsValid(BaseMsg))
	{
		BaseMsg = NewObject<UBaseMsg>();
		BaseMsg->MsgType = EMsgType::M_UMG;
	}
	Super::NativeConstruct();
}

void UBaseUMG::SendMsg(UBaseMsg* Msg)
{
	//TODO:ExecuteMsg
	UBaseFacade::GetMsgBaseManager(this)->ExecuteMsg(Msg);
}

void UBaseUMG::OnCreateUMG(int Index, bool FromPool)
{
	bFromPool = FromPool;
	UMGIndex = Index;
	OnBindLocalEvent();
	OnCreate();
}

void UBaseUMG::OnShowUMG()
{
	OnShow();
}

void UBaseUMG::OnHideUMG()
{
	OnHide();
}

void UBaseUMG::OnDestroyUMG()
{
	OnUnBindLocalEvent();
	OnDestroy();
}

void UBaseUMG::OnBindLocalEvent()
{
}

void UBaseUMG::OnUnBindLocalEvent()
{
}

void UBaseUMG::OnCreate_Implementation()
{
}

void UBaseUMG::OnShow_Implementation()
{
}

void UBaseUMG::OnHide_Implementation()
{
}

void UBaseUMG::OnDestroy_Implementation()
{
}
