// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "GridManager.h"


// Sets default values
AGridManager::AGridManager()
{
    // Enable ticking
    PrimaryActorTick.bCanEverTick = true;

    // Initialize default values
    SizeX = 10;
    SizeY = 10;
    CellSize = 100.0f;
}

// Called when the game starts or when spawned
void AGridManager::BeginPlay()
{
    Super::BeginPlay();
    InitializeGrid();
}

void AGridManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


}

void  AGridManager::InitializeGrid()
{
    FVector Origin = GetActorLocation();
    // Calculating the offset to move the grid's origin to the center
    FVector Offset = FVector(SizeX * CellSize / 2.0f, SizeY * CellSize / 2.0f, 0);

    for (int32 x = 0; x <= SizeX; x++)
    {
        FVector Start = Origin + FVector(x * CellSize, 0, 0) - Offset;
        FVector End = Start + FVector(0, SizeY * CellSize, 0);
        DrawDebugLine(GetWorld(), Start, End, FColor::White, true);
    }

    for (int32 y = 0; y <= SizeY; y++)
    {
        FVector Start = Origin + FVector(0, y * CellSize, 0) - Offset;
        FVector End = Start + FVector(SizeX * CellSize, 0, 0);
        DrawDebugLine(GetWorld(), Start, End, FColor::White, true);
    }
}