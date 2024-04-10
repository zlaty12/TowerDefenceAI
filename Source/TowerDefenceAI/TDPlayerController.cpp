// Fill out your copyright notice in the Description page of Project Settings.


#include "TDPlayerController.h"
#include "CameraPawn.h"
#include "InputMappingContext.h"
#include "Kismet/GameplayStatics.h"
#include "MainCharacter.h"
#include "CursorActor.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
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

void ATDPlayerController::SwapMappingContext()
{
    if (CameraPawn && !bPlayerIsDead)
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
        {
            // Remove the current mapping context
            Subsystem->RemoveMappingContext(CameraPawn->MappingContextCamera);

            // Add the new mapping context
            if (CameraPawn->FPSCharecter)
            {
                Subsystem->AddMappingContext(CameraPawn->FPSCharecter, 0);
                if (AMainCharacter* MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), AMainCharacter::StaticClass())))
                {
                    Possess(MainCharacter);
                }
                bShowMouseCursor = false;
                bEnableClickEvents = false;
                bEnableMouseOverEvents = false;

               
            }
          
               
                   
        }
    }


  
}

void ATDPlayerController::SwapToCamera()
{
    if (AMainCharacter* MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), AMainCharacter::StaticClass())))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
        {
            Subsystem->RemoveMappingContext(CameraPawn->FPSCharecter);

            if (CameraPawn->MappingContextCamera)
            {
                Subsystem->AddMappingContext(CameraPawn->MappingContextCamera, 0);
                Possess(CameraPawn);
            }
        }
        bShowMouseCursor = true;
        bEnableClickEvents = true;
        bEnableMouseOverEvents = true;
    }

}




void ATDPlayerController::OnClickPlace()
{
    if (ACursorActor* CursorActor = Cast<ACursorActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ACursorActor::StaticClass())))
    {
        CursorActor->PlaceOnClick();
    }
}



