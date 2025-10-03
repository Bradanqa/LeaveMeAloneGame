// LeaveMeAlone Game by Netologiya. All RightsReserved


#include "LMAPlayerController.h"

ALMAPlayerController::ALMAPlayerController()
{
	
}

void ALMAPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}
