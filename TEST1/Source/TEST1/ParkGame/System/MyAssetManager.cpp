// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAssetManager.h"

UMyAssetManager::UMyAssetManager() : Super()
{
}



UMyAssetManager& UMyAssetManager::Get()
{
	if (UMyAssetManager* Singleton = Cast<UMyAssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}

	return *NewObject<UMyAssetManager>();
}

