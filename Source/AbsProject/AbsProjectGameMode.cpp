// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "AbsProjectGameMode.h"
#include "AbsProjectPawn.h"
#include "AbsProjectHud.h"

AAbsProjectGameMode::AAbsProjectGameMode()
{
	DefaultPawnClass = AAbsProjectPawn::StaticClass();
	HUDClass = AAbsProjectHud::StaticClass();
}
