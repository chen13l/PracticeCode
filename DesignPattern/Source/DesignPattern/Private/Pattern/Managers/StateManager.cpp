// Fill out your copyright notice in the Description page of Project Settings.


#include "Pattern/Managers/StateManager.h"

UStateManager::UStateManager()
{
}

void UStateManager::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(StateManagerLog, Warning, TEXT("StateManager Initialize"));
	Super::Initialize(Collection);
}

void UStateManager::EnterState(TSubclassOf<ABaseState> StateClass)
{
	if (CurrentState != nullptr)
	{
		CurrentState->OnExitState();
	}
	CurrentState = GetState(StateClass);
	CurrentState->OnLevelChangeState();
	CurrentState->OnEnterState();
}

ABaseState* UStateManager::GetState(TSubclassOf<ABaseState> StateClass)
{
	ABaseState* State = nullptr;
	if (StatesMap.Contains(StateClass))
	{
		State = StatesMap.FindRef(StateClass);
	}
	else
	{
		if (UWorld* World = GetWorld())
		{
			FTransform Trans;
			State = World->SpawnActorDeferred<ABaseState>(StateClass, Trans);
			State->OnCreateState();
			StatesMap.Add(StateClass, State);
			State->FinishSpawning(Trans);
		}
	}
	return State;
}

ABaseState* UStateManager::GetCurrentState()
{
	if (IsValid(CurrentState)) { return CurrentState; }
	return nullptr;
}
