// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PraktykiGameModeBase.generated.h"


UCLASS()
class PRAKTYKI_API APraktykiGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void FinishedLap(APawn* Car);
	virtual void DestroyedCar(APawn* Car);
	virtual void TimeUp(APawn* Car);
	virtual void LapManager(APawn* Car, float Laps, float LapTime);

};
