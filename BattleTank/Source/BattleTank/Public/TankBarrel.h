// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent), hidecategories = (""))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, +1 is max up movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup )
	float MaxDegreePerSecond = 5; 

	UPROPERTY(EditAnywhere, Category = Setup )
	float MinElevationDegree= 0; // Minimum barrel elevation

	UPROPERTY(EditAnywhere, Category = Setup )
	float MaxElevationDegree = 40; // Maximum barrel elevation
	
};
