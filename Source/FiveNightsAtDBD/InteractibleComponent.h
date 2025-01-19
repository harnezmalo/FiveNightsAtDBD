// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractibleComponent.generated.h"

class UInteractibleComponent;

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FActorInteractionSignature, UInteractibleComponent, OnInteraction, ACharacter*, Character);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIVENIGHTSATDBD_API UInteractibleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractibleComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable, Category = "Components|Interaction")
	FActorInteractionSignature OnInteraction;

	UFUNCTION()
	void Interact(ACharacter* Character);
		
};
