// Copyright Gravinator Games. All Rights Reserved.

#include "EnTTForUnreal.h"
#include "EnTTWorldSubSystem.h"

void UEnTTWorldSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogEnTTSystem, Log, TEXT("Initialized EnTTWorldSubSystem."))
}

void UEnTTWorldSubSystem::Deinitialize()
{
	for (FSystem* System : Systems)
	{
		delete System;
	}
	
	UE_LOG(LogEnTTSystem, Log, TEXT("Deinitialized EnTTWorldSubSystem."))
}

bool UEnTTWorldSubSystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer);
}

bool UEnTTWorldSubSystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

void UEnTTWorldSubSystem::InitializeSystems()
{
	for (FSystem* System : Systems)
	{
		System->Initialize();
	}
}

void UEnTTWorldSubSystem::UpdateSystems(const float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(STAT_TotalUpdate)

	for (FSystem* System : Systems)
	{
		System->Update(Registry, DeltaTime);
	}
}

void UEnTTWorldSubSystem::RegisterSystem(FSystem* NewSystem, const FString Name)
{
	Systems.push_back(NewSystem);
	NamedSystems[Name] = NewSystem;
}

FSystem* UEnTTWorldSubSystem::GetSystem(const FString Name)
{
	return NamedSystems[Name];
}

void UEnTTWorldSubSystem::UpdateSystem(const FString Name, const float DeltaTime)
{
	GetSystem(Name)->Update(Registry, DeltaTime);
}

EEntity UEnTTWorldSubSystem::NewEntity()
{
	return Registry.create();
}

void UEnTTWorldSubSystem::DestroyEntity(const EEntity Entity)
{
	Registry.destroy(Entity);
}
