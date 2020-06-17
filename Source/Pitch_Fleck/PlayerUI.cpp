// Fill out your copyright notice in the Description page of Project Settings.
//#include "TimerManager.h"
#include "PlayerUI.h"
#include "Engine.h"

#include "string"


// Sets default values for this component's properties
APlayerUI::APlayerUI()
{
	MaxPlayerStamina = 1000;
	MaxPlayerHunger = 1000;
	playerStamina = 150;
	playerHunger = 1000;

	MaxPlayerTired = 1000;
	CurrentPlayerTired = 180;

	MaxPlayerHeals = 1000;
	CurrentPlayerHeals = 1000;

	playerTired = (float)CurrentPlayerTired/(float)MaxPlayerTired;//Percentage
	playerHeals = (float)CurrentPlayerHeals / (float)MaxPlayerHeals;//Percent
	myPos = GetActorLocation();
	
	gameSpeed = 1;
	playerRest = false;
}

void APlayerUI::SetGameInstance(UPitchGameInstance* pitchInst)
{
	pitchInst->OnGameSpeedCHange.AddDynamic(this, &APlayerUI::GameSpeedChanges);
}

void APlayerUI::GameSpeedChanges(float currSpeed, bool resting)
{
	//UE_LOG(LogWindows, Warning, TEXT("GameSpeedChanges!"));
	gameSpeed = currSpeed;
	playerRest = resting;
}


// Called when the game starts
void APlayerUI::BeginPlay()
{
	Super::BeginPlay();
	SetTimer();
	
	UPitchGameInstance* inst = Cast<UPitchGameInstance>(GetGameInstance());
	if(inst->IsValidLowLevel())
		inst->OnGameSpeedCHange.AddDynamic(this, &APlayerUI::GameSpeedChanges);

	// ...
	
}

void APlayerUI::ChangeHeals(int change_)
{
	//if (playerRest && change_ < 0)
		//return;

	CurrentPlayerHeals += change_;

	if (CurrentPlayerHeals < 0)
	{
		CurrentPlayerHeals = 0;
	}
	playerHeals = (float)CurrentPlayerHeals / (float)MaxPlayerHeals;
}

void APlayerUI::ChangeTired(int change_)
{
	FString str = FString::FromInt(change_);
	//UE_LOG(LogWindows, Warning, TEXT("change_ %s"), *str);

	CurrentPlayerTired += change_;
	
	str = FString::FromInt(CurrentPlayerTired);
	//UE_LOG(LogWindows, Warning, TEXT("CurrentPlayerTired %s"), *str);
	if (CurrentPlayerTired < 0)
	{
		CurrentPlayerTired = 0;
	}
	else if (CurrentPlayerTired > MaxPlayerTired)
	{
		CurrentPlayerTired = MaxPlayerTired;
	}
	

	playerTired = (float)CurrentPlayerTired / (float)MaxPlayerTired;
	
}

void APlayerUI::ChangeStamina(int staminaChange)
{
		playerStamina += staminaChange;
		if (playerStamina < 0)
		{
			playerStamina = 0;
			ChangeTired(staminaChange);
		}
		if (playerStamina > CurrentPlayerTired)
		{
			if (playerRest)
				ChangeTired(playerStamina - CurrentPlayerTired);
			else
				playerStamina = CurrentPlayerTired;//Если не отдыхает - выше усталости не поднимется
		}

		if (playerStamina > MaxPlayerStamina)
			playerStamina = MaxPlayerStamina;
}

void APlayerUI::ChangeHunger(int hungerChange)
{
	if (playerRest && hungerChange <= 0)
	{
		//UE_LOG(LogWindows, Warning, TEXT("hunger not change"));
		return;
	}

	if (hungerChange == 0)
	{
		hungerChange =  (5 - playerStamina / (MaxPlayerStamina / 4)) * -1;
		if (hungerChange < -4)
			hungerChange = -4;
	}

	playerHunger += hungerChange;
	if (playerHunger < 0)
	{
		playerHunger = 0;
		ChangeHeals(hungerChange);
	}
	else if(playerHunger > CurrentPlayerHeals)
	{
		playerHunger = CurrentPlayerHeals;
		//FString str = FString::FromInt(playerHeals);
		//UE_LOG(LogWindows, Warning, TEXT("playerHeals %s"), *str);
	}
}

void APlayerUI::ReduceStamina()
{
	FVector newPos = GetActorLocation();
	float deltaDist = (newPos - myPos).Size();
	if (deltaDist != 0)
	{
		currStaminaDist += deltaDist;
		ReSetTimer();

		myPos = newPos;
	}
	if (currStaminaDist >= distForStamina)
	{
		playerStamina--;
		if (playerStamina < 0)
		{
			playerStamina = 0;
			ChangeTired(-1);
		}
		currStaminaDist = 0;
	}
}

void APlayerUI::SetTimer()
{
	//UE_LOG(LogWindows, Warning, TEXT("Set"));
	GetWorld()->GetTimerManager().SetTimer(FRestTimer, this, &APlayerUI::OnRest, timeToRest/gameSpeed, false);
}
void APlayerUI::ReSetTimer()
{
	//UE_LOG(LogWindows, Warning, TEXT("ReSetTimer"));
	GetWorld()->GetTimerManager().ClearTimer(FRestTimer);
	SetTimer();
}

void APlayerUI::OnRest()
{
	//UE_LOG(LogWindows, Warning, TEXT("Rest"));
	ChangeStamina(1);

	SetTimer();
	
}
