// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BertieController.generated.h"

class UBehaviorTreeComponent;
class ABertieCharacter;
struct FAIStimulus;

UCLASS()
class FIVENIGHTSATDBD_API ABertieController : public AAIController
{
	GENERATED_BODY()
	

public:
	ABertieController(const FObjectInitializer& ObjectInitializer);

	UFUNCTION()
	void OnPerception(AActor* Actor, FAIStimulus Stimulus);

	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = true ))
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = true))
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;
};
