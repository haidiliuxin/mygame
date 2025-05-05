// Fill out your copyright notice in the Description page of Project Settings.


#include "Vharacter/enemyBace.h"

#include "Runtime/UMG/Public/Components/WidgetComponent.h"

AenemyBace::AenemyBace()
{
	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(RootComponent);
}
