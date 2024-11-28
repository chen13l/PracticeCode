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
