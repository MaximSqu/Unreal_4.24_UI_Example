// Fill out your copyright notice in the Description page of Project Settings.
#include "PlayerCheckItem.h"
#include "Components/InputComponent.h"
#include "Engine.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values for this component's properties
UPlayerCheckItem::UPlayerCheckItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerCheckItem::BeginPlay()
{
	Camera = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;

	
	Super::BeginPlay();
	
	
	// ...
	
}
void UPlayerCheckItem::UseFocusedItem()
{
	if (focusedItem)
	{
		UE_LOG(LogWindows, Warning, TEXT("Already"));
		//focusedItem->UseThis();
		IUsable::Execute_UseThis(focusedItem);
	}
}

// Called every frame
void UPlayerCheckItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FHitResult OutHit;
	FCollisionQueryParams CollisionParams;

	FVector position = Camera->GetCameraLocation();
	FVector forward = Camera->GetActorForwardVector();
	UE_LOG(LogWindows, Warning, TEXT("try focus"));

	if (GetWorld()->LineTraceSingleByChannel(OutHit, position, position + forward * itemUseDist, ECC_Visibility, CollisionParams))
	{
		UClass* CastClass = OutHit.GetActor()->GetClass();
		UE_LOG(LogWindows, Warning, TEXT("focus"));

		if (focusedItem != OutHit.GetActor() && CastClass->ImplementsInterface(UUsable::StaticClass()))
		{
			if (focusedItem)//Если смена фокуса на другой предмет
			{
				IUsable::Execute_EndFocus(focusedItem, Widget3D);
				//Widget3D->SetActorLocation(FVector(0, 0, -1090));//hidden

			}

			focusedItem = OutHit.GetActor();

			IUsable::Execute_StartFocus(focusedItem, Widget3D);

			//UE_LOG(LogWindows, Warning, TEXT("Focus on: %s and Interface is: %s"), OutHit.GetActor()->GetName(), focusedItem);
		}

	}
	else if(focusedItem)
	{
		IUsable::Execute_EndFocus(focusedItem, Widget3D);
		//Widget3D->SetActorLocation(FVector(0, 0, -1090));//Hidden

		focusedItem = nullptr;

	}
}

