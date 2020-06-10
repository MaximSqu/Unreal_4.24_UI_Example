// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Usable.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UsableItem.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PITCH_FLECK_API AUsableItem : public AActor, public IUsable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	AUsableItem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
		void UseThis_Implementation() override;
		void StartFocus_Implementation() override;
		void EndFocus_Implementation() override;
};
