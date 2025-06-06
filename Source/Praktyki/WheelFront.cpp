// Copyright 2023 Teyon. All Rights Reserved.


#include "WheelFront.h"

UWheelFront::UWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedByEngine = true;
	bAffectedBySteering = true;
	MaxSteerAngle = 40;
	WheelMass = 20;
	WheelRadius = 35;
	WheelWidth = 25;
	FrictionForceMultiplier = 3.2;
	bABSEnabled = true;
	bTractionControlEnabled = true;
	SlipThreshold = 50;
	CorneringStiffness = 3700;
}
