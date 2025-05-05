// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Vharacter/CharacterBace.h"
#include "enemyBace.generated.h"

class UWidgetComponent;
UCLASS()
class GAMEMY3_API AenemyBace : public ACharacterBace
{
	GENERATED_BODY()
public:

	AenemyBace();

	protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
