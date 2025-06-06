// Copyright 2023 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PraktykiGameModeBase.h"
#include "CheckpointActor.h"
#include "Kismet/GameplayStatics.h"
#include "TrainingLapGameMode.generated.h"

USTRUCT()
struct FRaceProgress
{
	GENERATED_BODY()

	UPROPERTY()
	int32 CurrentCheckpointIndex = 0;

	UPROPERTY()
	int32 CurrentLap = 1;
};

UCLASS()
class PRAKTYKI_API ATrainingLapGameMode : public APraktykiGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void FinishedLap(APawn* Car) override;
	virtual void DestroyedCar(APawn* Car) override;
	virtual void LapManager(APawn* Car, float Laps, float LapTime) override;
	virtual void TimeUp(APawn* Car) override;
	TMap<APawn*, FRaceProgress> CheckpointProgress;

	float MaxLapTime;
	float NumberOfLaps;
	float CurrentLap = 1;
	float CurrentLapTime;
	bool bRaceFinished = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LastLapTime = 0;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BestLapTime = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ACheckpointActor*> AllCheckpoints;

private:
	void EndGame(bool bIsPlayerWinner);
	void MuteAll(APawn* Car);
};
