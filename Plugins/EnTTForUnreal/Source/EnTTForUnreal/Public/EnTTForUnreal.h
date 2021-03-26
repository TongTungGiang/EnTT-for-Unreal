// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "ThirdParty/EnTT/entt/single_include/entt/entt.hpp"

// EnTT bridge in UE4 style

DECLARE_STATS_GROUP(TEXT("EnTT"), STATGROUP_EnTT, STATCAT_Advanced);
DECLARE_LOG_CATEGORY_EXTERN(LogEnTTSystem, Log, All)
DECLARE_CYCLE_STAT(TEXT("EnTT: Total System Update"), STAT_TotalUpdate, STATGROUP_EnTT);

using FRegistry = entt::registry;
using EEntity = entt::entity;

struct FSystem
{
	FString Name;
	virtual ~FSystem() {}
	virtual void Initialize() {}
	virtual void Update(FRegistry& Registry, float DeltaTime) = 0;
};

class FEnTTForUnrealModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
