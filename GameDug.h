// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameDug.generated.h"

/**
 * 
 */
UCLASS()
class GAMEMY3_API UGameDug : public UObject
{
	GENERATED_BODY()
	
};
namespace Debug {
	static void Print(FString Message,float ShowTime =3.0f,FColor Color=FColor::MakeRandomColor()){
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, ShowTime, Color, Message);
			//将信息输出到屏幕上
		}
		UE_LOG(LogTemp, Warning, TEXT("Message:%s"), *Message);
		//将信息显示到日志上
	}



}