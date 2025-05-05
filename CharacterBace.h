// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBace.generated.h"

UCLASS()
class GAMEMY3_API ACharacterBace : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBace();
	UPROPERTY(BlueprintReadWrite)
	bool IsDeath;

UFUNCTION(BlueprintCallable)
	void CharactorDamage(const float Damage);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite)
	float Health;
	UPROPERTY(BlueprintReadWrite)
	float MaxHealth;
UFUNCTION(BlueprintImplementableEvent)
	void DeathResponse();
};
