// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledtank() const
{
    return Cast<ATank>(GetPawn());
}

