// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MyTestingGroundsGameMode.h"
#include "MyTestingGroundsHUD.h"
#include "Player/MyFirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyTestingGroundsGameMode::AMyTestingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behavior/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMyTestingGroundsHUD::StaticClass();
}
