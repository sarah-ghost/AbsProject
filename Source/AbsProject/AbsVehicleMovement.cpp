// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsVehicleMovement.h"
#include "PhysXPublic.h"
#include "PhysXIncludes.h"
#include "Components/PrimitiveComponent.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "WheeledVehicleMovementComponent.h"




float UAbsVehicleMovement::CalcBrakeSmooth(int32 WheelIndex)
{
	return M2ToCm2(Wheels[WheelIndex]->MaxBrakeTorque - ManualBrakeSmooth);
}


void UAbsVehicleMovement::UpdateBrakes()
{
#if WITH_PHYSX_VEHICLES

	// Linear vehicle speed in KmH
	float speed = FMath::Abs(GetForwardSpeed() * 0.036f); 

	// Rotation speed of wheel in rad/s
	float wheelSpeed = ((PVehicle->mWheelsDynData.getWheelRotationSpeed(0)));
	
	// TODO ---------------------------------------------------------------------

    /** Perfect wheel rotation speed without sliping (rad/s)
			float omega = (((Speed * 0.28f) / Wheels[0]->ShapeRadius) * 2 * PI);

		Calculated slip from momental wheel rotation speed 
			float calcSlip =  1 - (omega / wheelSpeed);

		Real slip from debug
			float realSlip = Wheels[WheelIndex]->DebugLongSlip;	
	    
		CalcBrakeSmooth() should depend on these two parameters but now realSlip 
		not compatible with calculated.

		New brake value should depend on real wheel torque and should be compatible
		with it.

	 ----------------------------------------------------------------------------
	**/
	
	// Vehicle is moving and wheels to close to be lock.
	if (wheelSpeed < 1 && speed > 0) {

		// Set calculated brake torque to each wheel;
		for (int32 WheelIndex = 0; WheelIndex < WheelSetups.Num(); WheelIndex++)
		{
			Dummy = PVehicle->mWheelsSimData.getWheelData(WheelIndex);
			Dummy.mMaxBrakeTorque = CalcBrakeSmooth(WheelIndex);
			PVehicle->mWheelsSimData.setWheelData(WheelIndex, Dummy);
			
		}
	}
}
#endif

void UAbsVehicleMovement::UpdateSimulation(float DeltaTime)
{
	 
	
	if (bAbsEnabled) {
		UpdateBrakes();
	}
	
	Super::UpdateSimulation(DeltaTime);

}
