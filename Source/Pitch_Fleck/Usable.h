// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "UObject/Interface.h"
#include "Usable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalApi, Blueprintable)
class UUsable : public UInterface
{
	GENERATED_BODY()
};

class IUsable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void UseThis();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void StopUseThis();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void StartFocus();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void EndFocus();
};