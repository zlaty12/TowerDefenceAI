// Fill out your copyright notice in the Description page of Project Settings.


#include "TDPlayerController.h"
#include "CameraPawn.h"
#include "EnhancedInputSubsystems.h"


void ATDPlayerController::BeginPlay()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

	CameraPawn = Cast<ACameraPawn>(GetPawn());
	
	if (CameraPawn && CameraPawn->MappingContextCamera)
	{
		
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(CameraPawn->MappingContextCamera, 0);
		}
}
	}



