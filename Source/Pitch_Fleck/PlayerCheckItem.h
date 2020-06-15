// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "Engine.h"
#include "CoreMinimal.h"
#include "Usable.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/ActorComponent.h"
#include "PlayerCheckItem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PITCH_FLECK_API UPlayerCheckItem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerCheckItem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	APlayerCameraManager* Camera;
	UObject* focusedItem;
public:	
	UPROPERTY(EditAnywhere)
		AActor* Widget3D;
	UPROPERTY(EditAnywhere)
		int itemUseDist;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
		void UseFocusedItem();
	UFUNCTION(BlueprintCallable)
		void StopUseFocusedItem();
};
