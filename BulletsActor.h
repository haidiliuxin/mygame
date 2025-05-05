// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletsActor.generated.h"

UCLASS()
class GAMEMY3_API ABulletsActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletsActor();
UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void SetBulletMove(const FVector TargetPosVector);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
