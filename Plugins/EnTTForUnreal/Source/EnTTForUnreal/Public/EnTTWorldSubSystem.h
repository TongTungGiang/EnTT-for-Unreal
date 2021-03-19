// Copyright Gravinator Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnTTForUnreal.h"
#include "entity/registry.hpp"
#include "EnTTWorldSubSystem.generated.h"

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

/**
 * A world subsystem providing an interface to the EnTT framework
 */
UCLASS()
class ENTTFORUNREAL_API UEnTTWorldSubSystem final : public UWorldSubsystem
{
	GENERATED_BODY()

	// ==================================================
	// UWorldSubsystem
	// ==================================================
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

protected:
	virtual bool DoesSupportWorldType(EWorldType::Type WorldType) const override;

	// ==================================================
	// EnTT
	// ==================================================
public:
	FRegistry* GetRegistry() { return &Registry; }

	void InitializeSystems();

	void UpdateSystems(float DeltaTime);

	template<typename T>
	FSystem* CreateAndRegisterSystem(FString Name);

	template<typename T>
	FSystem* CreateAndRegisterSystem();

	void RegisterSystem(FSystem* NewSystem, FString Name);
	
	FSystem* GetSystem(FString Name);

	void UpdateSystem(FString Name, float DeltaTime);

	EEntity NewEntity();

	void DestroyEntity(EEntity Entity);
	
private:
	FRegistry Registry;
	TMap<FString, FSystem*> NamedSystems;
	std::vector<FSystem*> Systems;
};

