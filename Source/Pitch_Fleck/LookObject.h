// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "UObject/Interface.h"
#include "CoreMinimal.h"
#include "LookObject.generated.h"

/**
 * 
 */
UINTERFACE(MinimalApi, Blueprintable)
class ULookObject : public UInterface
{
	GENERATED_BODY()

};

class ILookObject
{
	GENERATED_BODY()
public:
	virtual void PlayerLook();
		
};