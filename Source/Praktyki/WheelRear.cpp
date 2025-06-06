// Copyright 2023 Teyon. All Rights Reserved.


#include "WheelRear.h"

UWheelRear::UWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	FrictionForceMultiplier = 3.2;
	bTractionControlEnabled = true;
	WheelMass = 20;
	WheelRadius = 35;
	WheelWidth = 25;
	bABSEnabled = true;
	SlipThreshold = 50;
	CorneringStiffness = 3700;
}
