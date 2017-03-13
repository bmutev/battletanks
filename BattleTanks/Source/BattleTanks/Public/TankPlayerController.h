// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
    virtual void BeginPlay() override;
    virtual void Tick( float DeltaSeconds ) override;

private:
    ATank* GetControlledTank() const;

    // Start the tank moving the barrel so that a shot would hit where
    // the crosshair intersects the world
    void AimTowardsCrosshair();
    bool FindSightRayHitLocation(FVector& HitLocation) const;
    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

    UPROPERTY(EditAnywhere)
    float CrossHairXLocation = 0.5f;

    UPROPERTY(EditAnywhere)
    float CrossHairYLocation = 0.333f;
};
