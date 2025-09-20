// Copyright Epic Games, Inc. All Rights Reserved.


#include "TruimphFPSShooterPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "TruimphFPSShooterCameraManager.h"

ATruimphFPSShooterPlayerController::ATruimphFPSShooterPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ATruimphFPSShooterCameraManager::StaticClass();
}

void ATruimphFPSShooterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
