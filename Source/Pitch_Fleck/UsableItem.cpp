// Fill out your copyright notice in the Description page of Project Settings.


#include "UsableItem.h"

// Sets default values for this component's properties
AUsableItem::AUsableItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	

	// ...
}


// Called when the game starts
void AUsableItem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void AUsableItem::EndFocus_Implementation()
{
	UE_LOG(LogWindows, Warning, TEXT("Endfocus"));
}

void AUsableItem::StartFocus_Implementation()
{
	UE_LOG(LogWindows, Warning, TEXT("Startfocus"));
}

void AUsableItem::UseThis_Implementation()
{
	UE_LOG(LogWindows, Warning, TEXT("Used from CPP"));
}

