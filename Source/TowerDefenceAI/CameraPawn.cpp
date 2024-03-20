// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"
#include "InputMappingContext.h"
#include "Kismet/KismetMathLibrary.h"
#include "MainCharacter.h"
#include "TDPlayerController.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FloatingPawnMovement = CreateDefaultSubobject <UFloatingPawnMovement>(TEXT("Floating Pawn Movment Component"));

	
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(InputMove, ETriggerEvent::Triggered, this, &ACameraPawn::CameraMove);
		Input->BindAction(InputSwap, ETriggerEvent::Triggered, this, &ACameraPawn::SwapMappingContext);
	}
}

void ACameraPawn::SwapMappingContext()
{
	if (ATDPlayerController* PlayerController = Cast<ATDPlayerController>(GetController()))
	{
		PlayerController->SwapMappingContext();
	}
}

void ACameraPawn::CameraMove(const FInputActionValue& Value)
{

	const FVector2D Direction = Value.Get<FVector2D>();

	if (Controller)
	{

		FRotator CurrentRotation = RootComponent->GetComponentRotation();
		FVector ForwardVector = UKismetMathLibrary::GetForwardVector(FRotator(0, CurrentRotation.Yaw, 0));
		FVector RightVector = UKismetMathLibrary::GetRightVector(FRotator(0, CurrentRotation.Yaw, 0));


		AddMovementInput(ForwardVector, Direction.Y);
		AddMovementInput(RightVector, Direction.X);
	}
}


	
