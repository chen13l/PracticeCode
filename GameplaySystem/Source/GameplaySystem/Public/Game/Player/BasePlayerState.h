// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BasePlayerState.generated.h"

class UInventoryComp;
/**
 * 
 */
UCLASS()
class GAMEPLAYSYSTEM_API ABasePlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ABasePlayerState();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual UInventoryComp* GetInventoryComp() const { return InventoryComp; }

protected:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UInventoryComp> InventoryComp;
};
