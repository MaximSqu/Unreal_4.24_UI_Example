// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Character.h"
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
	int MaxPlayerTired, CurrentPlayerTired;

	int MaxPlayerHeals, CurrentPlayerHeals;
	void ChangeTired(int change_);
	void ChangeHeals(int change_);
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	//virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadOnly)
		float playerHeals;
	UPROPERTY(BlueprintReadOnly)
		float playerTired;
	UPROPERTY(BlueprintReadOnly)
		float playerStamina;
	UPROPERTY(BlueprintReadOnly)
		float playerHunger;
	UFUNCTION(BlueprintCallable)
		void ChangeStamina(int staminaChange);
	UFUNCTION(BlueprintCallable)
		void ChangeHunger(int hungerChange);
	UFUNCTION(BlueprintCallable)
		void ReduceStamina();
};
