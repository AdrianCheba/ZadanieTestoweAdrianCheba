// Copyright 2023 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "InputActionValue.h"
#include "VehiclePawn.generated.h"


UCLASS()
class PRAKTYKI_API AVehiclePawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	AVehiclePawn();

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArm2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArm3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera4;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UAudioComponent* EngineSound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UNiagaraComponent* ExhaustRight;	

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UNiagaraComponent* ExhaustLeft;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* SteeringWheelMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UNiagaraComponent* NS_RR_Trail;	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UNiagaraComponent* NS_RL_Trail;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UNiagaraComponent* NS_FR_Trail;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UNiagaraComponent* NS_FL_Trail;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* BumperFront;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* Body;	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* HoodFront;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* FenderRight;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* FenderLeft;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* DoorRight;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* DoorLeft;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* Window;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* BootRear;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* BumperRear;	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* SpoilerBack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Material")
	class UMaterialInterface* DamageMaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Material")
	class UMaterialInterface* DamageLightMaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Material")
	class UMaterialInterface* DamageWindowMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UNiagaraComponent* DamageSmoke;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInstance* LightMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrentDamage = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DamageSite = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DamageTakeFront = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DamageTakeRear = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CurrentLapTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxLapTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float NumberOfLaps;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsOnTrack = true;
	
protected:
	
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* HandBrakeAction;
	
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* ThrottleAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* BrakeAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* LookAroundAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* LookUpDownAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* SteeringAction;	
	
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* SwitchCameraAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* RestartAction;
	
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* InteriorCameraLookAction;

	FTimerHandle MaxLapTimeHandle;

	UPROPERTY(EditAnywhere, Category = "Track Check")
	float RayDistance = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Track Check")
	FName TrackTag = "Track";

	UMaterialInstanceDynamic* DynamicLightMaterial;

	float SteeringInput;
	int ActiveCameraIndex;
	bool bFirstStart = true;
	float LastHitTime = 0.0f;
	float HitCooldown = 0.5f;
	
private:
	void MoveForward(const FInputActionValue& value);
	void OnBrakePressed(const FInputActionValue& value);
	void OnBrakeReleased(const FInputActionValue& value);
	void LookAround(const FInputActionValue& value);
	void LookUpDown(const FInputActionValue& value);
	void InteriorCameraLook();
	void InteriorCameraLookReleased();
	void Steering(const FInputActionValue& value);
	void SteeringReleased();
	void OnHandBrakePressed();
	void OnHandBrakeReleased();
	void OnThrottleReleased();
	void TurnRearLights(bool value);
	void IncreasedSmokeExhaust();
	void DecreasedSmokeExhaust();
	void SwitchCamera();
	void UpdateSteeringWheelRotation(float steeringInput);
	void ActivateTrails(bool isHandbrake);
	void DeactivateTrails();
	void RestartLevel();
	void TimeUp();
	void CheckIfOnTrack(); 
	float CalculateDirectionalDamage(const FHitResult& Hit);

	class AC_Path* PathRef;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	void OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
};
