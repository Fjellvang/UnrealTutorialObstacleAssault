// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	UPROPERTY(EditAnywhere, Category="Rotating Platform")
	FRotator RotationSpeed{ 0,0,0 };

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector Speed{ 50,0,0 };
	UPROPERTY(VisibleAnywhere, Category="Moving Platform")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	double MaxDistance{ 100 };
	UPROPERTY(VisibleAnywhere, Category="Moving Platform")
	double MaxDistanceSquared;
};
