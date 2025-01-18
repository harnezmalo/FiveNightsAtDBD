// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BertieCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBertieEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBertieHealthEvent, float, healh);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEventMachin, float, machin, int, truc);

UCLASS()
class FIVENIGHTSATDBD_API ABertieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABertieCharacter();

	UPROPERTY(BlueprintAssignable)
	FBertieEvent OnBertie;

	UFUNCTION()
	void StartChase();

	UFUNCTION()
	void EndChase();

	UFUNCTION()
	void CatchPlayer();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Start Chase"))
	void OnStartChase();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On End Chase"))
	void OnEndChase();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Catch Player"))
	void OnCatchPlayer();

	UFUNCTION(BlueprintCallable)
	bool GetChaseState() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	bool bIsChasing;

	UPROPERTY(EditAnywhere)
	float WanderingSpeed;

	UPROPERTY(EditAnywhere)
	float ChaseSpeed;

	UPROPERTY(EditAnywhere)
	float WanderingAcceleration;

	UPROPERTY(EditAnywhere)
	float ChaseAcceleration;

};
