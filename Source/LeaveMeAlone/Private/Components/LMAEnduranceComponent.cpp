// LeaveMeAlone Game by Netologiya. All RightsReserved


#include "Components/LMAEnduranceComponent.h"

// Sets default values for this component's properties
ULMAEnduranceComponent::ULMAEnduranceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void ULMAEnduranceComponent::BeginPlay()
{
	Super::BeginPlay();

	Endurance = MaxEndurance;
}

void ULMAEnduranceComponent::OnEnduranceChanging(float Value)
{
	Endurance = FMath::Clamp(Endurance - Value, 0.0f, MaxEndurance);
	OnEnduranceChanged.Broadcast(Endurance);
}

float ULMAEnduranceComponent::GetEndurance() const
{
	return Endurance;
}

float ULMAEnduranceComponent::GetEnduranceDrainRate() const
{
	return EnduranceDrainRate;
}

bool ULMAEnduranceComponent::IsEnduranceOut() const
{
	return Endurance <= 0.0f;
}

void ULMAEnduranceComponent::RestoreEndurance(float DeltaTime)
{
	if (Endurance >= MaxEndurance) {
		return;
	}

	TimeSinceLastDrain += DeltaTime;
	if (TimeSinceLastDrain >= EnduranceRestoreDelay)
	{
		Endurance = FMath::Min(MaxEndurance, Endurance + EnduranceRestoreRate * DeltaTime);
		OnEnduranceChanged.Broadcast(Endurance);
	}
}

void ULMAEnduranceComponent::ConsumeEndurance(float Amount)
{
	const float OldEndurance = Endurance;
	Endurance = FMath::Max(0.0f, Endurance - Amount);
	TimeSinceLastDrain = 0.0f;

	if (!FMath::IsNearlyEqual(OldEndurance, Endurance))
	{
		OnEnduranceChanged.Broadcast(Endurance);
	}
}
