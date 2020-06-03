// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Character.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerUI.generated.h"


UCLASS()
class PITCH_FLECK_API APlayerUI : public ACharacter
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	APlayerUI();

protected:
	FVector myPos;
	int MaxPlayerStamina, MaxPlayerHunger;
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
		float playerStamina;
	UPROPERTY(BlueprintReadOnly)
		float playerHunger;
	UFUNCTION(BlueprintCallable)
		void ReduceStamina();
	UFUNCTION(BlueprintCallable)
		void ReduceHunger();
	UFUNCTION(BlueprintCallable)
		void ChangeStaminaMomently(int staminaChange);
};
