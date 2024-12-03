// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySystem/Public/InventorySystem/InventoryComp.h"

#include "GameFramework/Character.h"
#include "GameplaySystem/GameplaySystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"


UInventoryComp::UInventoryComp()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	CurrentTraceActor = InteractiveTrace();
	if(CurrentTraceActor != LastTraceActor)
	{
		//TODO:

		
		LastTraceActor = CurrentTraceActor;	
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInventoryComp::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION(UInventoryComp, Content, COND_OwnerOnly);
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

AActor* UInventoryComp::InteractiveTrace()
{
	FVector ActorLocation = UGameplayStatics::GetPlayerCharacter(this,0)->GetActorLocation();
	FVector ActorForwardVector = UGameplayStatics::GetPlayerCameraManager(this,0)->GetActorForwardVector();
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

void UInventoryComp::AddToInventory()
{
}

void UInventoryComp::RemoveFormInventory()
{
}
