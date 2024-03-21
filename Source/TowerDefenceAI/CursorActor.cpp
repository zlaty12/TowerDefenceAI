// Fill out your copyright notice in the Description page of Project Settings.


#include "CursorActor.h"
#include "GridManager.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

ACursorActor::ACursorActor()
{
    PrimaryActorTick.bCanEverTick = true;

    CursorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CursorMesh"));
    RootComponent = CursorMesh;
}

FVector ACursorActor::GetCursorPosition() const
{
    return GetActorLocation();
}

void ACursorActor::PlaceOnClick()
{
    if (GridManager)
    {
        GridManager->OnClick(GetActorLocation());
    }
}



void ACursorActor::BeginPlay()
{
    Super::BeginPlay();

    GridManager = Cast<AGridManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AGridManager::StaticClass()));
    if (!GridManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("GridManager not found in the level"));
    }
}

void ACursorActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateCursorPosition();
}

void ACursorActor::UpdateCursorPosition()
{
    if (!GridManager)
    {
        return;
    }

    FVector MousePosition;
    FVector MouseDirection;
    if (GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(MousePosition, MouseDirection))
    {
        FHitResult HitResult;
        if (GetWorld()->LineTraceSingleByChannel(HitResult, MousePosition, MousePosition + MouseDirection * 10000.0f, ECC_Visibility))
        {
            FVector SnappedPosition;
            if (GridManager->GetSnapPosition(HitResult.Location, SnappedPosition))
            {
                SetActorLocation(SnappedPosition);
                SetActorHiddenInGame(false);
            }
            else
            {
                SetActorHiddenInGame(true);
            }
        }
        else
        {
            SetActorHiddenInGame(true);
        }
    }
}