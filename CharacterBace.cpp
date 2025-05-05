// Fill out your copyright notice in the Description page of Project Settings.


#include "Vharacter/CharacterBace.h"

#include "Components/CapsuleComponent.h"

// Sets default values
ACharacterBace::ACharacterBace()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
Health=100;
	
}

void ACharacterBace::CharactorDamage(const float Damage)
{
	if (Health>0)
	{
		Health -= Damage;
		if (Health<=0)
		{
			Health=0;
			if (Health<=0)
			{
				IsDeath=true;
				GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
DeathResponse();

				
			}
		}
		
	}
}

// Called when the game starts or when spawned
void ACharacterBace::BeginPlay()
{
	Super::BeginPlay();
	MaxHealth=Health;
}


