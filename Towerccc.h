

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Towerccc.generated.h"
class UStaticMeshComponent;
class USceneComponent;
UCLASS()
class GAMEMY3_API ATowerccc : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ATowerccc();


	
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
    void UpdateDisplayTowerPoint();
	
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void RestDisplay();

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void Towerattach();


protected:
	
	virtual void BeginPlay() override;
    UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(BlueprintReadWrite)
	bool Iscreat=false;


};
