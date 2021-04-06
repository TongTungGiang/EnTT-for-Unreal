#pragma once

#include "EnTTCore.h"
#include "EnTTComponents.h"

struct FMovementSystem : public FSystem
{
	void Update(FRegistry& Registry, float DeltaTime) override
	{

	}
};

struct FRegisterComponentsSystem : public FSystem
{
	void Initialize(FRegistry& Registry) override
	{
		entt::meta<FLocation>().type();
		entt::meta<FScale>().type();
	}

	void Exit(FRegistry& Registry) override
	{
		for (auto EnttType : entt::resolve())
		{
			EnttType.reset();
		}
	}
};

struct FCreateExampleEntitiesSystem : public FSystem
{
	void Initialize(FRegistry& Registry) override
	{
		auto TestEntity = Registry.create();

		Registry.emplace<FLocation>(TestEntity, FLocation{ FVector() });
		Registry.emplace<FScale>(TestEntity, FScale{ FVector() });
	}
};