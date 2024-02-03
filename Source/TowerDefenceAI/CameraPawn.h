// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "CameraPawn.generated.h"

UCLASS()
class TOWERDEFENCEAI_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* MappingContextCamera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		class	UInputAction* InputMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Possessions")
		class TSubclassOf<ACharacter> PossessedCharecter;
private:
	UPROPERTY(VisibleAnywhere)
		class UFloatingPawnMovement* FloatingPawnMovement;

	void CameraMove(const FInputActionValue& Value);

	
};
