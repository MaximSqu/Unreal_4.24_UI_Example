// Fill out your copyright notice in the Description page of Project Settings.

#include "UsableItem.h"
#include "Kismet/KismetMathLibrary.h"

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
	//widget3D->SetActorHiddenInGame(true);
	
}

void AUsableItem::StartFocus_Implementation()
{
	/*if (!widget3D)
	{
		UE_LOG(LogWindows, Warning, TEXT("ERROR! widget empty"));

		return;
	}
	UE_LOG(LogWindows, Warning, TEXT("Startfocus, change widget loc"));
	widget3D->SetActorLocation(GetActorLocation());
	FVector MyCharacter = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FRotator setRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), MyCharacter);
	widget3D->SetActorRotation(setRotation, ETeleportType::TeleportPhysics);
	//widget3D->SetActorHiddenInGames(false);
	*/
}

void AUsableItem::UseThis_Implementation()
{
	UE_LOG(LogWindows, Warning, TEXT("Used from CPP"));
}

void AUsableItem::StopUseThis_Implementation()
{
	UE_LOG(LogWindows, Warning, TEXT("Stop Used from CPP"));
}