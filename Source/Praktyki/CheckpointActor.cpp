// Copyright 2023 Teyon. All Rights Reserved.


#include "CheckpointActor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "PraktykiGameModeBase.h"

// Sets default values
ACheckpointActor::ACheckpointActor()
{
	CollisonBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisonBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisonBox;

	CollisonBox->OnComponentBeginOverlap.AddDynamic(this, &ACheckpointActor::OnOverlapBegin);
}

void ACheckpointActor::ActivateCheckpoint()
{
	IsDeactivated = false;
	RootComponent->Activate();
}

void ACheckpointActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACheckpointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACheckpointActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsDeactivated) return;

	IsDeactivated = true;

	APraktykiGameModeBase* GameMode = GetWorld()->GetAuthGameMode<APraktykiGameModeBase>();
	APawn* OtherActorPawn = Cast<APawn>(OtherActor);

	if (GameMode && OtherActorPawn)
		GameMode->FinishedLap(OtherActorPawn);

	RootComponent->Deactivate();
}

