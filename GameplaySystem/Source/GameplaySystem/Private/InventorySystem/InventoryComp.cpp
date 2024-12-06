// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySystem/Public/InventorySystem/InventoryComp.h"

#include "Camera/CameraComponent.h"
#include "GameplaySystem/GameplaySystem.h"
#include "GameplaySystem/GameplaySystemCharacter.h"
#include "InventorySystem/UI/ViewModels/InventoryViewModel.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"


UInventoryComp::UInventoryComp()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	/*CurrentTraceActor = InteractiveTrace();
	if (CurrentTraceActor != LastTraceActor)
	{
		//TODO:


		LastTraceActor = CurrentTraceActor;
	}*/
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInventoryComp::BeginPlay()
{
	Super::BeginPlay();

	InventoryViewModel = NewObject<UInventoryViewModel>(this, InventoryViewModelClass);
	InventoryViewModel->SetInventorySize(GetInventorySize());
}

void UInventoryComp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION(UInventoryComp, Content, COND_OwnerOnly);
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

AActor* UInventoryComp::InteractiveTrace()
{
	FVector ActorLocation = OwnCharacter->GetActorLocation();
	FVector ActorForwardVector = OwnCharacter->GetFirstPersonCameraComponent()->GetForwardVector();
	FVector TraceEnd = ActorLocation + (ActorForwardVector * InteractionRange);
	FHitResult HitResult;

	UKismetSystemLibrary::SphereTraceSingle(this,
	                                        ActorLocation,
	                                        TraceEnd,
	                                        TraceSphereRadius,
	                                        UEngineTypes::ConvertToTraceType(ECC_Interactive),
	                                        false,
	                                        IgnoreActors,
	                                        EDrawDebugTrace::None,
	                                        HitResult,
	                                        true);
	return HitResult.bBlockingHit ? HitResult.GetActor() : nullptr;
}


void UInventoryComp::AddToInventory(int32 Quantity, const FName& ItemName)
{
	int32 ItemIndex = GetItemIndexByName(ItemName);
	if (ItemIndex == -1)
	{
		const int32 EmptySlotIndex = FindEmptySlot();
		if (EmptySlotIndex != -1)
		{
			Content[EmptySlotIndex].ItemName = ItemName;
			Content[EmptySlotIndex].Nums = 0;
			ItemIndex = EmptySlotIndex;
		}
		else
		{
			if (Content.Num() < GetInventorySize())
			{
				FSlotStruct NewSlotStruct;
				NewSlotStruct.ItemName = ItemName;
				NewSlotStruct.Nums = 0;
				Content.Add(NewSlotStruct);
				ItemIndex = GetItemIndexByName(ItemName);
			}
			else
			{
				UKismetSystemLibrary::PrintString(this, "have not empty space");
				return;
			}
		}
	}

	if (ItemDataTable == nullptr)
	{
		UKismetSystemLibrary::PrintString(this, "ItemDataTable hasn't set");
		return;
	}
	const FItemStruct* ItemStruct = ItemDataTable->FindRow<FItemStruct>(ItemName, *ItemName.ToString(), false);
	check(ItemStruct);
	const int32 ItemMaxStack = ItemStruct->StackSize;

	const int32 ItemNumsInPackage = Content[ItemIndex].Nums;
	if (ItemNumsInPackage < ItemMaxStack)
	{
		Content[ItemIndex].Nums = FMath::Clamp(ItemNumsInPackage + Quantity, ItemNumsInPackage, ItemMaxStack);
	}
	else
	{
		UKismetSystemLibrary::PrintString(this, "can not pick more");
	}
}

void UInventoryComp::RemoveFormInventory()
{
}

void UInventoryComp::Pick()
{
	AActor* Item = InteractiveTrace();
	if (Item && Item->Implements<UItemInteraction>())
	{
		AddToInventory(1, IItemInteraction::Execute_GetItemName(Item));
		IItemInteraction::Execute_Picked(Item);
	}
}

int32 UInventoryComp::GetItemIndexByName(const FName& ItemName) const
{
	for (int32 i = 0; i < Content.Num(); ++i)
	{
		if (Content[i].ItemName == ItemName) { return i; }
	}
	return -1;
}

int32 UInventoryComp::FindEmptySlot() const
{
	for (int32 i = 0; i < Content.Num(); ++i)
	{
		if (Content[i].Nums <= 0) { return i; }
	}
	return -1;
}
