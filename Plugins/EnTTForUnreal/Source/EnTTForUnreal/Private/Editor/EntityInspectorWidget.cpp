// Copyright Gravinator Games.


#include "Editor/EntityInspectorWidget.h"

#include "EnTTWorldSubSystem.h"
#include "EnTTForUnreal.h"

UEntityInspectorWidget::UEntityInspectorWidget()
{

}

UEntityInspectorWidget::~UEntityInspectorWidget()
{

}

void UEntityInspectorWidget::Foo(const FString& EntityId)
{
	UWorld* World = GetGameplayWorld();
	if (World == nullptr)
	{
		UE_LOG(LogEnTTSystem, Log, TEXT("No active world!"));
		return;
	}

	UE_LOG(LogEnTTSystem, Log, TEXT("UEntityInspectorWidget World: %d"), World->GetUniqueID());
	UEnTTWorldSubSystem* EnttSubsystem = World->GetSubsystem<UEnTTWorldSubSystem>();
	if (EnttSubsystem == nullptr)
	{
		UE_LOG(LogEnTTSystem, Log, TEXT("No active UEnTTWorldSubSystem in the current world!"));
		return;
	}

	uint32 RawEntityId;
	LexFromString(RawEntityId, *EntityId);
	FRegistry& Registry = *EnttSubsystem->GetRegistry();
	EEntity Entity = static_cast<EEntity>(RawEntityId);
	if (!Registry.valid(Entity))
	{
		UE_LOG(LogEnTTSystem, Log, TEXT("Entity %d is not valid"), Entity);
		return;
	}

	UE_LOG(LogEnTTSystem, Log, TEXT("Iterating through component list of test entity: %d"), Entity);
	Registry.visit(Entity, [Entity](const entt::type_info TypeInfo)
		{
			std::string StdTypeName = std::string(TypeInfo.name());
			FString TypeName(StdTypeName.c_str());
			UE_LOG(LogEnTTSystem, Log, TEXT("Entity [%d] has component [%s]"),
				Entity,
				*TypeName);

		});
}

UWorld* UEntityInspectorWidget::GetGameplayWorld()
{ 
	// Prefer PIE Worlds.
	// Fallback to Game Preview Worlds.
	// Ignore all other types (e.g., other preview worlds).

	UWorld* PIE = nullptr;
	UWorld* GamePreview = nullptr;

	for (FWorldContext const& Context : GEngine->GetWorldContexts())
	{
		switch (Context.WorldType)
		{
		case EWorldType::PIE:
			PIE = Context.World();
			break;
		case EWorldType::GamePreview:
			GamePreview = Context.World();
			break;
		}
	}

	if (PIE)
	{
		return PIE;
	}
	else if (GamePreview)
	{
		return GamePreview;
	}

	return nullptr;
}
