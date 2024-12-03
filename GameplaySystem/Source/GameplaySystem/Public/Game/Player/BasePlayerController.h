// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class GAMEPLAYSYSTEM_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	ABasePlayerController();

	virtual void BeginPlay() override;

	// Input
	virtual void Pick();

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> TestAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	// ~End Input
};
