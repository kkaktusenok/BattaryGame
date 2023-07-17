// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BattaryMan_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class BATTARYGAME_API ABattaryMan_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	ABattaryMan_GameMode();
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<APawn> PlayerREcharge;

	float Spawn_Z = 500.f;
	
	UPROPERTY(EditAnywhere)
	float Spawn_X_Min;

	UPROPERTY(EditAnywhere)
	float Spawn_X_Max;

	UPROPERTY(EditAnywhere)
	float Spawn_Y_Min;

	UPROPERTY(EditAnywhere)
	float Spawn_Y_Max;

	void SpawnPlayerRecharge();
	
protected:
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
