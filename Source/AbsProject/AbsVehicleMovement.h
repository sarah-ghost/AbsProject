// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicleMovementComponent.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "PhysXPublic.h"
#include "AbsVehicleMovement.generated.h"

/**
 * 
 */
UCLASS()
class ABSPROJECT_API UAbsVehicleMovement : public UWheeledVehicleMovementComponent4W
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere)
	bool bAbsEnabled = true;
	UPROPERTY(EditAnyWhere)
	float ManualBrakeSmooth = 500.0f;

	PxVehicleWheelData Dummy;

	virtual float CalcBrakeSmooth(int32 WheelIndex);
	void UpdateBrakes();
	void UpdateSimulation(float DeltaTime);
	
};
