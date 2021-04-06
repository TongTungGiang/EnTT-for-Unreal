#pragma once

#include "EnTTGameMode.h"
#include "EnTTExampleGameMode.generated.h"

UCLASS()
class ENTTEXAMPLE_API AEnTTExampleGameMode : public AEnTTGameMode
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnTTExampleGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void CreateAndRegisterSystems() override;
};
