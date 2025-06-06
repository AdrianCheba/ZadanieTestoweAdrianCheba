// Copyright 2023 Teyon. All Rights Reserved.


#include "RacePlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void ARacePlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen && !WinScreen->IsVisible()) 
			WinScreen->AddToViewport();
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen && !LoseScreen->IsVisible())
			LoseScreen->AddToViewport();
	}
}

