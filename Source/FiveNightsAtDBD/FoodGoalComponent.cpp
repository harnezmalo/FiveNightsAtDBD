// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodGoalComponent.h"

#include "GregCharacter.h"

// Sets default values for this component's properties
UFoodGoalComponent::UFoodGoalComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UFoodGoalComponent::DepositFood(ACharacter* Character)
{
	if (AGregCharacter* greg = Cast<AGregCharacter>(Character))
	{
		if(greg->FoodHeld)
		{
			greg->FoodHeld->Destroy();
			greg->FoodHeld = nullptr;
			++FoodCollected;
			OnFoodDeposited.Broadcast();

			if (CheckIfCompletedGoal())
				OnGoalCompleted.Broadcast();
		}
	}
}

bool UFoodGoalComponent::CheckIfCompletedGoal() const
{
	return FoodCollected >= NumberOfFoodToCollect;
}

// Called when the game starts
void UFoodGoalComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFoodGoalComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

