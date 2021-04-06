
#include "EnTTExampleGameMode.h"

#include "EnTTSystems.h"
#include "EnTTWorldSubSystem.h"

// Sets default values
AEnTTExampleGameMode::AEnTTExampleGameMode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnTTExampleGameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnTTExampleGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnTTExampleGameMode::CreateAndRegisterSystems()
{
	EnTTWorld->CreateAndRegisterSystem<FMovementSystem>();
}

