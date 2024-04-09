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

    UFUNCTION(BlueprintCallable, Category = "Grid")
    bool IsPositionWithinGrid(const FVector& Position) const;
    
    UFUNCTION(BlueprintCallable, Category = "Grid")
    void OnClick(const FVector& CursorPosition);

    UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<AActor> ActorClassToSpawn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curancy")
    float Curancy = 150.0f;

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

    UPROPERTY(EditAnywhere, Category = "Grid")
    bool bLineIsVisable = true;

    void DrawGrid();
   
   
};
