// LeaveMeAlone Game by Netologiya. All RightsReserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UDecalComponent;
class UMaterialInterface;
class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;
class ULMAEnduranceComponent;
class ULMAWeaponComponent;
class UAnimMontage;


UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMADefaultCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float YRotation = -75.0f;
	float FOV = 55.0f;
	float ArmLength = 1400.0f;
	float SprintMaxSpeed = 450;
	float WalkMaxSpeed = 300;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartSprint();
	void EndSprint();
	void ZoomCamera(float Value);

	void RotationPlayerOnCursor();

	void OnDeath();
	void OnHealthChanged(float NewHealth);
	void OnEnduranceChanged(float NewEndurance);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Health")
	ULMAHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Endurance")
	ULMAEnduranceComponent* EnduranceComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	ULMAWeaponComponent* WeaponComponent;

	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);
	
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	int MinArmLength = 400;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	int MaxArmLength = 1400;

	bool IsSprinting = false;

public:	
	UFUNCTION()
	ULMAHealthComponent* GetHealthComponent() const;

	UFUNCTION()
	ULMAEnduranceComponent* GetEnduranceComponent() const;
};
