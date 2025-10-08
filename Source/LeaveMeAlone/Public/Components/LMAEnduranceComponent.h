// LeaveMeAlone Game by Netologiya. All RightsReserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LMAEnduranceComponent.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FOnEnduranceChanged, float)


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEAVEMEALONE_API ULMAEnduranceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULMAEnduranceComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float Endurance = 0.0f;

	void OnEnduranceChanging(float Value);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Endurance")
	float MaxEndurance = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Endurance")
	float EnduranceRestoreRate = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Endurance")
	float EnduranceDrainRate = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Endurance")
	float EnduranceRestoreDelay = 2.0f;

	float TimeSinceLastDrain = 0.0f;

public:
	UFUNCTION(BlueprintCallable)
	float GetEndurance() const;
	float GetEnduranceDrainRate() const;

	bool IsEnduranceOut() const;
	void RestoreEndurance(float DeltaTime);
	void ConsumeEndurance(float Amount);

	FOnEnduranceChanged OnEnduranceChanged;
		
};
