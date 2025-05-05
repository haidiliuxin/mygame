// Fill out your copyright notice in the Description page of Project Settings.


#include "Towerccc.h"

// Sets default values
ATowerccc::ATowerccc()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    Root=CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	Mesh=CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ATowerccc::BeginPlay()
{
	Super::BeginPlay();
	
}




