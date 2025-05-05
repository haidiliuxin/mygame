// Fill out your copyright notice in the Description page of Project Settings.



#include "Vharacter/PlayerBace.h"

#include"GameDug.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
APlayerBace::APlayerBace()
{

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
}

void APlayerBace::BeginPlay()
{
	
	Super::BeginPlay();
	Debug::Print(TEXT("GAMESTATE"));
}

void APlayerBace::Move(FVector2D MoveDir)
{
	if (Controller != nullptr) {
		FRotator Rotation = GetControlRotation();
		FRotator YawRoation(0, Rotation.Yaw, 0);
		FVector ForwardDir = FRotationMatrix(YawRoation).GetUnitAxis(EAxis::X);//获得正前方的方向
	    FVector RightDir = FRotationMatrix(YawRoation).GetUnitAxis(EAxis::Y);//获得正右方
		AddMovementInput(ForwardDir, MoveDir.X);//控制前后；
		AddMovementInput(RightDir, MoveDir.Y);//控制左右
	}
}

void APlayerBace::Look(FVector2D LookDir)
{
	if (Controller != nullptr) {
		AddControllerYawInput(LookDir.X);
		AddControllerPitchInput(LookDir.Y);
	}
}
