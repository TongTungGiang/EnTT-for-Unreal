#pragma once

#include "EnTTForUnreal.h"

#include "EnTTSystem.generated.h"

USTRUCT()
struct FSystem
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name;

	virtual ~FSystem() = default;
	virtual void Initialize() {};
	virtual void Update(FRegistry& Registry, float DeltaTime) {};
};
