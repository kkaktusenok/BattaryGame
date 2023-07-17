// Fill out your copyright notice in the Description page of Project Settings.


#include "BattaryMan_GameMode.h"

ABattaryMan_GameMode::ABattaryMan_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABattaryMan_GameMode::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle,
		this,
		&ABattaryMan_GameMode::SpawnPlayerRecharge,
		FMath::RandRange(2,5),
		true);
}

void ABattaryMan_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABattaryMan_GameMode::SpawnPlayerRecharge()
{
	float RandX = FMath::RandRange(Spawn_X_Min,Spawn_X_Max);
	float RandY = FMath::RandRange(Spawn_Y_Min,Spawn_Y_Max);

	FVector SpawnPosition = FVector(RandX,RandY,Spawn_Z);
	FRotator SpawnRotation = FRotator(0.f,0.f,0.f);

	GetWorld()->SpawnActor(PlayerREcharge, &SpawnPosition, &SpawnRotation);
}