// Copyright 2023 Teyon. All Rights Reserved.


#include "TrainingLapGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "CheckpointActor.h"
#include "TimerManager.h"
#include "Components/AudioComponent.h"

void ATrainingLapGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundCheckpoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACheckpointActor::StaticClass(), FoundCheckpoints);

	AllCheckpoints.Empty();

	for (AActor* Actor : FoundCheckpoints)
	{
		ACheckpointActor* Checkpoint = Cast<ACheckpointActor>(Actor);
		if (Checkpoint)
			AllCheckpoints.Add(Checkpoint);
	}

	AllCheckpoints.Sort([](const ACheckpointActor& A, const ACheckpointActor& B)
	{
		return A.CheckpointIndex < B.CheckpointIndex;
	});

	if (AllCheckpoints.Num() > 0)
		AllCheckpoints[0]->ActivateCheckpoint();
}


void ATrainingLapGameMode::FinishedLap(APawn* Car)
{
	if (bRaceFinished) return;

	FRaceProgress* Progress = CheckpointProgress.Find(Car);
	if (!Progress)
	{
		FRaceProgress NewProgress;
		CheckpointProgress.Add(Car, NewProgress);
		Progress = CheckpointProgress.Find(Car);
	}

	int32 NextCheckpointIndex = Progress->CurrentCheckpointIndex + 1;

	if (NextCheckpointIndex >= AllCheckpoints.Num())
	{
		LastLapTime = CurrentLapTime - LastLapTime;

		if (BestLapTime == 0.0f || LastLapTime < BestLapTime)
			BestLapTime = LastLapTime;

		CurrentLapTime = 0.0f;

		Progress->CurrentLap++;

		if (Progress->CurrentLap > NumberOfLaps)
		{
			bRaceFinished = true;
			bool bIsPlayer = Car->IsPlayerControlled();
			MuteAll(Car);
			EndGame(bIsPlayer);
			return;
		}
		else
			Progress->CurrentCheckpointIndex = 0;
	}
	else
	{
		Progress->CurrentCheckpointIndex = NextCheckpointIndex;
	}

	if (AllCheckpoints.IsValidIndex(Progress->CurrentCheckpointIndex))
	{
		AllCheckpoints[Progress->CurrentCheckpointIndex]->ActivateCheckpoint();
	}
}


void ATrainingLapGameMode::DestroyedCar(APawn* Car)
{
	Super::DestroyedCar(Car);

	APlayerController* PlayerController = Cast<APlayerController>(Car->GetController());
	if (PlayerController) 
	{
		EndGame(false);
		MuteAll(Car);
	}
}

void ATrainingLapGameMode::LapManager(APawn* Car, float Laps, float LapTime)
{
	NumberOfLaps = Laps;
	CurrentLapTime = LapTime;
}

void ATrainingLapGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld())) 
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
		GetWorld()->GetWorldSettings()->SetTimeDilation(0.0f);
	}
}

void ATrainingLapGameMode::MuteAll(APawn* Car)
{
	TArray<UAudioComponent*> AudioComponents;
	Car->GetComponents<UAudioComponent>(AudioComponents);
	for (UAudioComponent* AudioComponent : AudioComponents)
	{
		if (AudioComponent)
			AudioComponent->SetVolumeMultiplier(0.0f);
	}
}

void ATrainingLapGameMode::TimeUp(APawn* Car)
{
	EndGame(false);
	MuteAll(Car);
}
