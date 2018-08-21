// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void  UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we're replacing the functionality
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto MovementThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMovement(MovementThrow);

	auto TurningThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurning(TurningThrow);

	// UE_LOG(LogTemp, Warning, TEXT("%s vectoring %s"), *TankName, *MoveVelocityString)
}

void  UTankMovementComponent::IntendMovement(float Throw)
{
	if (!LeftTrack|| !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	// TODO prevent double speed due to dual input
}

void  UTankMovementComponent::IntendTurning(float Throw)
{
	if (!LeftTrack|| !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	// TODO prevent double speed due to dual input
}




