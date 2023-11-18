// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	MaxDistanceSquared = MaxDistance * MaxDistance;

	UE_LOG(LogTemp, Display, TEXT("StartLocation: %s"), *StartLocation.ToString());
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::RotatePlatform(float DeltaTime) 
{
	//FRotator CurrentRotation = GetActorRotation();
	//CurrentRotation += RotationSpeed * DeltaTime;
	//SetActorRotation(CurrentRotation);

	AddActorLocalRotation(RotationSpeed * DeltaTime); // Prevents gimbal lock
}
void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();

	FVector Distance = CurrentLocation - StartLocation;

	double DistanceSquared = Distance.SquaredLength();
	SetActorLocation(CurrentLocation + (Speed * DeltaTime));
	if ((MaxDistanceSquared) < DistanceSquared)
	{
		StartLocation = StartLocation + (MaxDistance * Speed.GetSafeNormal());
		SetActorLocation(StartLocation);
		Speed *= -1;
	}
}

