// Copyright 2023 Teyon. All Rights Reserved.


#include "C_Path.h"
#include "Components/SplineComponent.h"


AC_Path::AC_Path()
{

	PrimaryActorTick.bCanEverTick = true;

	SplinePath = CreateDefaultSubobject<USplineComponent>(TEXT("SplinePath"));

}


void AC_Path::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_Path::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


