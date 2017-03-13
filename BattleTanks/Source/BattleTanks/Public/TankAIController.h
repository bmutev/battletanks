// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
    virtual void BeginPlay() override;

private:
    virtual void Tick( float DeltaSeconds ) override;

    ATank* GetControlledTank() const;	
    ATank* GetPlayerTank() const;

    // Move tank turret towards aim direction
    void AimTowardsCrosshair();
};
