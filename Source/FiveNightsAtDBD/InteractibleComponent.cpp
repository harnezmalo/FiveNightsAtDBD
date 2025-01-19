// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractibleComponent.h"

// Sets default values for this component's properties
UInteractibleComponent::UInteractibleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UInteractibleComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UInteractibleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UInteractibleComponent::Interact(ACharacter* Character)
{
	OnInteraction.Broadcast(Character);
}

