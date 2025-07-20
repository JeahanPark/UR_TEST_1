// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "MyAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class TEST1_API UMyAssetManager : public UAssetManager
{GENERATED_BODY()

public:
	UMyAssetManager();
	static UMyAssetManager& Get();

	template<typename AssetType>
	static AssetType* GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer);
};

template<typename AssetType>
AssetType* UMyAssetManager::GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer)
{
	AssetType* LoadedAsset = nullptr;
	const FSoftObjectPath* AssetPath = AssetPointer.ToSoftObjectPath();

	if (AssetPath->IsValid())
	{
		LoadedAsset = AssetPointer.Get();
		if (LoadedAsset)
			return LoadedAsset;
	}
		
	return nullptr;
}
