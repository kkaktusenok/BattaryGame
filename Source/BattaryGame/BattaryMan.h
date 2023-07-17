// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "BattaryMan.generated.h"

UCLASS()
class BATTARYGAME_API ABattaryMan : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABattaryMan();

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Camera")
	UCameraComponent* FollowCamera;

	void MoveForward(float Axis);
	void MoveRight(float Axis);

	bool bDead;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Power;

	UPROPERTY(EditAnywhere)
	float Power_Treshold;

	UFUNCTION()
	void OnBeginOverlap(
		UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult & HitResult);

	UPROPERTY(EditAnywhere,Category="UI HUD")
	TSubclassOf<UUserWidget> PlayerPowerWidgetClass;
	UUserWidget* PlayerPowerWidget;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
