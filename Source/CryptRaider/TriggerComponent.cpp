// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	if (Actors.Num() > 0)
	{
		Actors[0];
		for (int i = 0 ; i<Actors.Num() ; i++)
		{
			UE_LOG(LogTemp,Display,TEXT("%i. Actor : %s"),i+1 ,*Actors[i]->GetActorNameOrLabel());
		}
			
	}

}
