// Fill out your copyright notice in the Description page of Project Settings.
//#include "TimerManager.h"
#include "PlayerUI.h"
#include "Engine.h"
#include "string"



// Sets default values for this component's properties
APlayerUI::APlayerUI()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void APlayerUI::BeginPlay()
{
	Super::BeginPlay();
	
	MaxPlayerStamina = 1000;
	MaxPlayerHunger = 1000;
	playerStamina = 150;
	playerHunger = 1000;

	MaxPlayerTired = 1000;
	CurrentPlayerTired = 1000;
	playerTired = 1.0;//Percentage
	myPos = GetActorLocation();
	// ...
	
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
	}
}