// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*FRotator MyRotation = GetComponentRotation();
	FString RotationString = MyRotation.ToCompactString();
	UE_LOG(LogTemp,Display,TEXT("Grabber Rotation: %s"),*RotationString);
	
	float WorldTime = GetWorld()->TimeSeconds;
	UE_LOG(LogTemp, Display, TEXT("World time: %f"), WorldTime);
	UE_LOG(LogTemp, Display, TEXT("BBB"));
	
	float Damage = 2;
	float& DamageRef = Damage;
	DamageRef = 5;
	UE_LOG(LogTemp,Display,TEXT("DamageRef: %f, Damage: %f"), DamageRef, Damage);

	float Damage;
	if (HasDamage(Damage))
	{
		PrintDamage(Damage);
	}
	UE_LOG(LogTemp,Display,TEXT("Original Damage: %f"),Damage)*/

	FVector Start = GetComponentLocation();
	FVector End = GetForwardVector()*MaxGrabDistance+Start;
	DrawDebugLine(GetWorld(),Start,End, FColor::Red);

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start,End,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Sphere
		);

	if (HasHit)
	{
		AActor* HitActor = HitResult.GetActor();
		UE_LOG(LogTemp,Display,TEXT("Hit actor : %s"),*HitActor->GetActorNameOrLabel());
	}
	else
	{
		UE_LOG(LogTemp,Display,TEXT("No Actor Hit!"));
	}
	
}

/*void UGrabber::PrintDamage(const float& Damage)
{
	UE_LOG(LogTemp,Display,TEXT("Damage: %f"),Damage);
}

bool UGrabber::HasDamage(float& OutDamage)
{
	OutDamage = 5;
	return true;
}*/



