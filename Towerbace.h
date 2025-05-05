// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Towerbace.generated.h"
class UStaticMeshComponent;
class USceneComponent;
class AenemyBace;
class ABulletsActor;
UCLASS()
class GAMEMY3_API ATowerbace : public AActor
{GENERATED_BODY()
	
public:	
	
	ATowerbace();
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void SetTowerMTBlue();
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void SetTowerMTRed();
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void ResetMT();
UFUNCTION(BlueprintCallable)
void CheckAttackRanageEnemy();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> BaseMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> BodyMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> BarrelMesh;

UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<USceneComponent> BulletPoint;
	

	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AenemyBace> CurrentEnemy;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float AttackTime;
UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<ABulletsActor> BulletClass;
	
UFUNCTION()
void CheckEnemy();
FTimerHandle CheckTimerHandle;
UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void RotateTarget();
	UFUNCTION(BlueprintCallable)
	void AttacklookEnemy();
	
	UFUNCTION()
	void AttackCallBack();
	UFUNCTION()
	void lookCallBack();
	FTimerHandle AttackTimerHandle;
	FTimerHandle LookTimerHandle;
};
