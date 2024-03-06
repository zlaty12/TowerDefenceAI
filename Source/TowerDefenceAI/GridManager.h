// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GridManager.generated.h"

UCLASS()
class TOWERDEFENCEAI_API AGridManager : public APawn
{
	GENERATED_BODY()

public:
    AGridManager();

    UFUNCTION(BlueprintCallable, Category = "Grid")
    bool GetSnapPosition(const FVector& WorldPosition, FVector& OutSnappedPosition) const;

   
    
   



protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "Grid")
    float GridSize;

    UPROPERTY(EditAnywhere, Category = "Grid")
    int32 NumCells;

    UPROPERTY(EditAnywhere, Category = "Grid")
    float GridThickness;

    UPROPERTY(EditAnywhere, Category = "Grid")
    FColor GridColor;

    void DrawGrid();
    bool IsPositionWithinGrid(const FVector& Position) const;
};
