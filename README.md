# Anti-lock Brake System Prototype
for Unreal Engine 4.24 PhysXVehicles
based on VehicleAdvanced Template C++

[Lil' Documentation](https://github.com/sarah-ghost/AbsProject/blob/master/AbsDoc.docx?raw=true)

> ABS implemented as a new vehicle movement component which is inherited from this template movement component. 

> Standart pawn's vehicle movement was replaced by new class.

> 8 out of 10 estimated hours I spent reading NVidia PhysX documentation.


TODO

    Perfect wheel rotation speed without sliping (rad/s)
			float omega = (((Speed * 0.28f) / Wheels[0]->ShapeRadius) * 2 * PI);

		Calculated slip from momental wheel rotation speed (NVIDIA says it's in rad/s!)
			float calcSlip =  1 - (omega / wheelSpeed);

		Real slip from debug
			float realSlip = Wheels[WheelIndex]->DebugLongSlip;	
	    
		CalcBrakeSmooth() should depend on these two parameters but now realSlip 
		not compatible with calculated.

		New brake value should depend on real wheel torque and should be compatible
		with it.
