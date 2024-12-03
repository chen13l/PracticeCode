// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/ItemInteraction.h"
#include "BaseItem.generated.h"

class UItemDataComp;

UCLASS(Blueprintable, BlueprintType)
class GAMEPLAYSYSTEM_API ABaseItem : public AActor, public IItemInteraction
{
	GENERATED_BODY()

public:
	ABaseItem();

protected:
	virtual void BeginPlay() override;

	// IItemInteraction
	virtual void Picked_Implementation() override;
	// ~IItemInteraction

	UPROPERTY(VisibleAnywhere, Category="Interactable Item")
	TObjectPtr<UItemDataComp> ItemDataComp;

	// Properties
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

	// ~Properties
	
public:
};
