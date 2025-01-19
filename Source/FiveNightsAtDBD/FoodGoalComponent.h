// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FoodGoalComponent.generated.h"

class UFoodGoalComponent;

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FOnFoodDepositedEvent, UFoodGoalComponent, OnFoodDeposited);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FOnGoalCompletedEvent, UFoodGoalComponent, OnGoalCompleted);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIVENIGHTSATDBD_API UFoodGoalComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFoodGoalComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
	int NumberOfFoodToCollect;

	UPROPERTY(BlueprintAssignable, Category = "Components|Goal")
	FOnFoodDepositedEvent OnFoodDeposited;

	UPROPERTY(BlueprintAssignable, Category = "Components|Goal")
	FOnGoalCompletedEvent OnGoalCompleted;

	UFUNCTION(BlueprintCallable)
	void DepositFood(ACharacter* Character);

private:
	UPROPERTY()
	int FoodCollected;

	UFUNCTION()
	bool CheckIfCompletedGoal() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
