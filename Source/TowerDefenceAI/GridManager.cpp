// Fill out your copyright notice in the Description page of Project Settings.


#include "GridManager.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"

// Sets default values
AGridManager::AGridManager()

    {
        PrimaryActorTick.bCanEverTick = false;

        GridSize = 100.0f;
        NumCells = 10;
        GridThickness = 2.0f;
        GridColor = FColor::White;
    }

void AGridManager::BeginPlay()
{
    Super::BeginPlay();
    DrawGrid();
}

bool AGridManager::GetSnapPosition(const FVector& WorldPosition, FVector& OutSnappedPosition) const
{
    if (IsPositionWithinGrid(WorldPosition))
    {
        FVector GridPosition = WorldPosition - GetActorLocation();
        FVector GridCoordinate = GridPosition / GridSize;

        int32 SnapX = FMath::RoundToInt(GridCoordinate.X);
        int32 SnapY = FMath::RoundToInt(GridCoordinate.Y);

        FVector SnappedGridCoordinate(SnapX, SnapY, 0.0f);
        OutSnappedPosition = GetActorLocation() + SnappedGridCoordinate * GridSize;

        return true;
    }
    return false;
}

void AGridManager::DrawGrid()
{
    FVector Center = GetActorLocation();
    FVector Extent = FVector(NumCells * GridSize * 0.5f);

    for (int32 i = 0; i <= NumCells; i++)
    {
        float XOffset = i * GridSize - Extent.X;
        FVector Start = Center + FVector(XOffset, -Extent.Y, 0.0f);
        FVector End = Center + FVector(XOffset, Extent.Y, 0.0f);
        DrawDebugLine(GetWorld(), Start, End, GridColor, true, -1.0f, 0, GridThickness);

        Start = Center + FVector(-Extent.X, XOffset, 0.0f);
        End = Center + FVector(Extent.X, XOffset, 0.0f);
        DrawDebugLine(GetWorld(), Start, End, GridColor, true, -1.0f, 0, GridThickness);
    }
}

bool AGridManager::IsPositionWithinGrid(const FVector& Position) const
{
    FVector Center = GetActorLocation();
    FVector Extent = FVector(NumCells * GridSize * 0.5f);
    float Tolerance = GridSize * 0.1f;

    return (Position.X >= Center.X - Extent.X - Tolerance && Position.X <= Center.X + Extent.X + Tolerance &&
        Position.Y >= Center.Y - Extent.Y - Tolerance && Position.Y <= Center.Y + Extent.Y + Tolerance);
}

void AGridManager::OnClick(const FVector& CursorPosition)
{
    if (IsPositionWithinGrid(CursorPosition) && Curancy >= 100.f)
    {
        FVector SpawnLocation = CursorPosition;
        FRotator SpawnRotation = FRotator::ZeroRotator;

        ACharacter* SpawnedActor = GetWorld()->SpawnActor<ACharacter>(ActorClassToSpawn, SpawnLocation, SpawnRotation);

        Curancy -= 10.f;
        if (SpawnedActor)
        {
            UE_LOG(LogTemp, Warning, TEXT("Actor spawned successfully at location: %s"), *SpawnLocation.ToString());
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to spawn actor at location: %s"), *SpawnLocation.ToString());
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Clicked position is outside the grid boundaries."));
    }
}
