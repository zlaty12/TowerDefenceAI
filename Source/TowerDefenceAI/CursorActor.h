// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CursorActor.generated.h"

UCLASS()
class TOWERDEFENCEAI_API ACursorActor : public APawn
{
	GENERATED_BODY()


public:
    ACursorActor();



    UFUNCTION(BlueprintCallable, Category = "Cursor")
    FVector GetCursorPosition() const;
    void PlaceOnClick();
protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(EditAnywhere, Category = "Components")
    UStaticMeshComponent* CursorMesh;

    UPROPERTY(EditAnywhere, Category = "Grid")
   class AGridManager* GridManager;

    UPROPERTY(EditAnywhere, Category = "Camera")
class    UCameraComponent* CameraComponent;

    void UpdateCursorPosition();
};
