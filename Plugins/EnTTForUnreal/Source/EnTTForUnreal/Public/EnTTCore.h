// Copyright Gravinator Games. All Rights Reserved.

#pragma once

#include "ThirdParty/EnTT/entt/single_include/entt/entt.hpp"
#include "EnTTCore.generated.h"

// EnTT bridge in UE4 style

DECLARE_STATS_GROUP(TEXT("EnTT"), STATGROUP_EnTT, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("EnTT: Total System Update"), STAT_TotalUpdate, STATGROUP_EnTT);

using FRegistry = entt::registry;
using EEntity = entt::entity;

USTRUCT()
struct FSystem
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name;

	virtual ~FSystem() = default;
	virtual void Initialize(FRegistry& Registry) {};
	virtual void Update(FRegistry& Registry, float DeltaTime) {};
	virtual void Exit(FRegistry& Registry) {};
};
