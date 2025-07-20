// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "TEST1/Test01LogChannels.h"
//#include "TEST1/ParkGame//Character/ACharacter.h"
#include "TEST1/ParkGame//Player/MyPlayerController.h"
AMyGameModeBase::AMyGameModeBase()
{

	//ConstructorHelpers::FClassFinder<ACharacter> character(TEXT("/Script/CoreUObject.Class'/Script/TEST1.ACharacter'"));

	//if (character.Succeeded())
	//	DefaultPawnClass = character.Class;
}

void AMyGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

}
