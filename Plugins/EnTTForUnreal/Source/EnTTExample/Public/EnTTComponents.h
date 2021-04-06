#pragma once

#include "EnTTComponents.generated.h"

USTRUCT(BlueprintType)
struct FLocation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FVector Location;
};

USTRUCT(BlueprintType)
struct FRotation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FQuat Rotation;
};

USTRUCT(BlueprintType)
struct FScale
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FVector Location;
};
