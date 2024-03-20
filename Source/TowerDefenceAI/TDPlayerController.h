// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include"CameraPawn.h"
#include "GameFramework/PlayerController.h"
#include "TDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENCEAI_API ATDPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	

public:
	virtual void BeginPlay() override;
	void SwapMappingContext();
private:
	ACameraPawn* CameraPawn;

	
protected:

	
};
