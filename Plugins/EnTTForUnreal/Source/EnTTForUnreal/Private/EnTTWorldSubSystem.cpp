// Copyright Gravinator Games. All Rights Reserved.

#include "EnTTWorldSubSystem.h"

DEFINE_LOG_CATEGORY(LogEnTTSystem)

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

void UEnTTWorldSubSystem::UpdateSystems(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(STAT_TotalUpdate)

	for (FSystem* System : Systems)
	{
		System->Update(Registry, DeltaTime);
	}
}

template <typename T>
FSystem* UEnTTWorldSubSystem::CreateAndRegisterSystem(const FString Name)
{
	FSystem* System = new T();

	if (System)
	{
		System->Name = Name;
		Systems.push_back(System);
		NamedSystems.Add(Name, System);
	}
	return System;
}

template <typename T>
FSystem* UEnTTWorldSubSystem::CreateAndRegisterSystem()
{
	FSystem* System = new T();

	if (System)
	{
		System->Name = "Unnamed";
		Systems.push_back(System);
		//NamedSystems.Add(Name, System);
	}
	return System;
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
