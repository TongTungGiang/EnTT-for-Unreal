#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameMode.h"
#include "EnTTGameMode.generated.h"

class UEnTTWorldSubSystem;

UCLASS()
class ENTTFORUNREAL_API AEnTTGameMode : public AGameMode
{
	GENERATED_BODY()

	UPROPERTY()
	UEnTTWorldSubSystem* EnTTWorld;
	
public:
	// Sets default values for this actor's properties
	AEnTTGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void CreateAndRegisterSystems();
};
