// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//Move the barrel the right amount this frame
	//Given a max elavation speed and the frame time
	auto ClampRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = ClampRelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation= RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
	
}



