// Fill out your copyright notice in the Description page of Project Settings.


#include "InputMappingContext.h"
#include "TDPlayerController.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Add input mappings for the main character
        Input->BindAction(SwapToCamera, ETriggerEvent::Triggered, this, &AMainCharacter::SwapMoppingCamera);
        // ...
    }
}

void AMainCharacter::SwapMoppingCamera()
{
    if (ATDPlayerController* PlayerController = Cast<ATDPlayerController>(GetController()))
    {
        PlayerController->SwapToCamera();
    }
}
