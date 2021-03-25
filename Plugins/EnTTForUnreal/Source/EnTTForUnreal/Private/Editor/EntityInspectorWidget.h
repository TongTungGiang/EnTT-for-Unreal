// Copyright Gravinator Games.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "EntityInspectorWidget.generated.h"

/**
 * 
 */
UCLASS()
class UEntityInspectorWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
	
public:

	UEntityInspectorWidget();
	~UEntityInspectorWidget();

	UFUNCTION(BlueprintCallable)
	void Foo();
};
