// Copyright 2023 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Path.generated.h"

UCLASS()
class PRAKTYKI_API AC_Path : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_Path();

	UPROPERTY(EditAnywhere, BlueprintReadWrite);
		class USplineComponent* SplinePath;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
