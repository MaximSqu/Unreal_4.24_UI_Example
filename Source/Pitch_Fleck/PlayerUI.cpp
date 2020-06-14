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
	CurrentPlayerTired = 1000;

	MaxPlayerHeals = 1000;
	CurrentPlayerHeals = 1000;

	playerTired = 1.0;//Percentage
	playerHeals = 1.0;//Percent
	myPos = GetActorLocation();
}


// Called when the game starts
void APlayerUI::BeginPlay()
{
	Super::BeginPlay();
	
	
	// ...
	
}

void APlayerUI::ChangeHeals(int change_)
{
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
	UE_LOG(LogWindows, Warning, TEXT("change_ %s"), *str);

	CurrentPlayerTired += change_;
	
	str = FString::FromInt(CurrentPlayerTired);
	UE_LOG(LogWindows, Warning, TEXT("CurrentPlayerTired %s"), *str);
	if (CurrentPlayerTired < 0)
	{
		CurrentPlayerTired = 0;
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
}

void APlayerUI::ChangeHunger(int hungerChange)
{
	if (hungerChange == 0)
	{
		hungerChange =  (5 - playerStamina / (MaxPlayerStamina / 4)) * -1;
		if (hungerChange > 4)
			hungerChange = 4;
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
	FString strPos = newPos.ToString();
	if ((newPos - myPos).Size() > 200)
	{
		playerStamina--;
		if (playerStamina < 0)
		{
			playerStamina = 0;
			ChangeTired(-1);
		}
		myPos = newPos;
	}
}