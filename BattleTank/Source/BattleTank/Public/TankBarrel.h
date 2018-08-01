// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), hidecategories = (""))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup )
	float MaxDegreePerSecond = 20; // Sensible default

	UPROPERTY(EditAnywhere, Category = Setup )
	float MinElevationPerSecond = 0; // Minimum barrel elevation

	UPROPERTY(EditAnywhere, Category = Setup )
	float MaxElevationPerSecond = 40; // Maximum barrel elevation
	
};
