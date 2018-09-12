// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector HitLocation;

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	//Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius ); // TODO check radius in cm?

	// Aim toward player
	auto AimingComponent = ControlledTank -> FindComponentByClass<UTankAimingComponent>(); 
	AimingComponent -> AimAt(PlayerTank -> GetActorLocation());

	//TODO fix firing
	//ControlledTank->Fire(); // TODO limit firing rate
	
}



