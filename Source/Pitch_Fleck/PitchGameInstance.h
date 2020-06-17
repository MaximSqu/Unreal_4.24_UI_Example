// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Delegates/Delegate.h"
#include "PitchGameInstance.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameSpeedCHange, float, speed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGameSpeedDelegate, float, currSpeed, bool, rest);


UCLASS()
class PITCH_FLECK_API UPitchGameInstance : public UGameInstance
{
	GENERATED_BODY()
protected:
	float GameSpeed = 1.0f;
public:
	UFUNCTION(BlueprintCallable)
		void ChangeGameSpeed(float multiplier, bool isRest);
	UPROPERTY(BlueprintAssignable)
		FGameSpeedDelegate OnGameSpeedCHange;
};
