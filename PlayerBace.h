// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Vharacter/CharacterBace.h"
#include"PlayerBace.generated.h"

class USpringArmComponent;
class UCameraComponent;
UCLASS()
class GAMEMY3_API APlayerBace : public ACharacterBace
{
	GENERATED_BODY()
public:
	APlayerBace();
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	TObjectPtr<UCameraComponent> FollowCamera;

	UFUNCTION(BlueprintCallable)
	void Move(FVector2D MoveDir);
	UFUNCTION(BlueprintCallable)
	void Look(FVector2D LookDir);
};
