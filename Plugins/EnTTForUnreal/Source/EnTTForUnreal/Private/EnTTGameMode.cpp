// Copyright Gravinator Games. All Rights Reserved.

#include "EnTTGameMode.h"
#include "EnTTWorldSubSystem.h"

// Sets default values
AEnTTGameMode::AEnTTGameMode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnTTGameMode::BeginPlay()
{
	Super::BeginPlay();

	EnTTWorld = GetWorld()->GetSubsystem<UEnTTWorldSubSystem>();

	CreateAndRegisterSystems();

	EnTTWorld->InitializeSystems();
}

// Called every frame
void AEnTTGameMode::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	EnTTWorld->UpdateSystems(DeltaTime);
}

void AEnTTGameMode::CreateAndRegisterSystems()
{
	
}
