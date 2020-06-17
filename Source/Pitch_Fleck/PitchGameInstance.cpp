// Fill out your copyright notice in the Description page of Project Settings.


#include "PitchGameInstance.h"


void UPitchGameInstance::ChangeGameSpeed(float changeSpeed, bool isRest)
{
	//UE_LOG(LogWindows, Warning, TEXT("call speed change"));
	GameSpeed *= changeSpeed;
	OnGameSpeedCHange.Broadcast(changeSpeed, isRest);
}