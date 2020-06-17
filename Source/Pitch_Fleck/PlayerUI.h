// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Character.h"
#include "Components/ActorComponent.h"
#include "PitchGameInstance.h"
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
	FTimerHandle FRestTimer;
	float currStaminaDist;
	bool playerRest;
	int MaxPlayerHeals, CurrentPlayerHeals;
	void ChangeTired(int change_);
	void ChangeHeals(int change_);
	void SetTimer();
	void OnRest();

	// Called when the game starts
	virtual void BeginPlay() override;

	


public:	
	UFUNCTION()
		void GameSpeedChanges(float currSpeed, bool resting);


	//virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
		float timeToRest;
	UPROPERTY(EditAnywhere)
		float distForStamina;
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
	UFUNCTION(BlueprintCallable)
		void ReSetTimer();

	UFUNCTION(BlueprintCallable)
		void SetGameInstance(UPitchGameInstance* pitchInstance);

	UPROPERTY(BlueprintReadOnly)
		float gameSpeed;
};
