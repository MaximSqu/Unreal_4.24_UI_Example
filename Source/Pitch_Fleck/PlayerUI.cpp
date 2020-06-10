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
	CurrentPlayerHeals = 150;

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
	playerHeals = CurrentPlayerHeals / 1000.0;
}

void APlayerUI::ChangeTired(int change_)
{
	CurrentPlayerTired += change_;
	
	if (CurrentPlayerTired < 0)
	{
		CurrentPlayerTired = 0;
	}
	playerTired = CurrentPlayerTired / 1000.0;
}
void APlayerUI::ReduceStamina()
{
	FVector newPos = GetActorLocation();
	FString strPos = newPos.ToString();
	if ((newPos - myPos).Size() > 200)
	{
		playerStamina --;
		if (playerStamina < 0)
		{
			playerStamina = 0;
			ChangeTired(-1);
		}
		myPos = newPos;
	}
}
void APlayerUI::ChangeStaminaMomently(int staminaChange)
{
		playerStamina += staminaChange;
		if (playerStamina < 0)
		{
			playerStamina = 0;
			ChangeTired(staminaChange);
		}
}
void APlayerUI::ReduceHunger()
{
	int reduceHunger = 5 - playerStamina / (MaxPlayerStamina / 4);

	playerHunger -= reduceHunger;
	if (playerHunger < 0)
	{
		playerHunger = 0;
		ChangeHeals(-1);
	}
}