// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower/Towerbace.h"

#include "GameDug.h"
#include "Engine/OverlapResult.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Vharacter/enemyBace.h"
#include "BulletsActor.h"

// Sets default values
ATowerbace::ATowerbace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<UStaticMeshComponent>("Root");
	SetRootComponent(Root);

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaceMesh");
	BaseMesh->SetupAttachment(Root);
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("BodyMesh");
	BodyMesh->SetupAttachment(Root);
	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>("BarrelMesh");
	BarrelMesh->SetupAttachment(BodyMesh);
BulletPoint = CreateDefaultSubobject<USceneComponent>("BulletPoint");
BulletPoint->SetupAttachment(Root);
	AttackTime=1.0f;


}

void ATowerbace::CheckAttackRanageEnemy()
{
	GetWorld()->GetTimerManager().SetTimer(CheckTimerHandle,this,&ATowerbace::CheckEnemy,0.2f,true);
	
}

void ATowerbace::CheckEnemy()
{
	TArray<FOverlapResult>Results;
	FVector pos=GetActorLocation();
	bool isoverlap=GetWorld()->OverlapMultiByChannel(Results,pos,FQuat::Identity,ECollisionChannel::ECC_Pawn,FCollisionShape::MakeSphere(600.0f));
	if (isoverlap)
	{
		for (const FOverlapResult Result : Results)
		{

  if (Result.GetActor())
{
	AenemyBace* Enemy= Cast<AenemyBace>(Result.GetActor());
      if (Enemy)
    {
	//找到了敌人，清除计时器
	   Debug::Print(TEXT("find enemy"));
      	CurrentEnemy=Enemy;
      	RotateTarget();
    
        GetWorldTimerManager().ClearTimer(CheckTimerHandle);
	    break;
     }


}
			
		}
	}
}

void ATowerbace::AttacklookEnemy()
{
Debug::Print(TEXT("hellow4"));
    GetWorldTimerManager().SetTimer(AttackTimerHandle,this,&ATowerbace::AttackCallBack,AttackTime,true);
	GetWorldTimerManager().SetTimer(LookTimerHandle,this,&ATowerbace::lookCallBack,0.05f,true);
}

void ATowerbace::AttackCallBack()
{
   Debug::Print(TEXT("short"));
	if (CurrentEnemy)
	{
		check(BulletClass);
		ABulletsActor*	Bullet=GetWorld()->SpawnActor<ABulletsActor>(BulletClass,BulletPoint->GetComponentLocation(),BulletPoint->GetComponentRotation());
		Bullet->SetBulletMove(CurrentEnemy->GetActorLocation());
	}
	
	
}

void ATowerbace::lookCallBack()
{

	FVector CurrentLotation=GetActorLocation();
	FVector TargetLotation=CurrentEnemy->GetActorLocation();
    FVector Direction=TargetLotation-CurrentLotation;
Direction.Z=0;
	Direction.Normalize();
	FRotator Rotation=UKismetMathLibrary::MakeRotFromX(Direction);
SetActorRotation(Rotation);

	if (CurrentEnemy->IsDeath)
	{
		CurrentEnemy=nullptr;
		GetWorldTimerManager().ClearTimer(AttackTimerHandle);
		GetWorldTimerManager().ClearTimer(LookTimerHandle);
	}

	
}

// Called when the game starts or when spawned
void ATowerbace::BeginPlay()
{
	Super::BeginPlay();
	
}



