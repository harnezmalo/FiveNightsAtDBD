// Fill out your copyright notice in the Description page of Project Settings.


#include "BertieCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABertieCharacter::ABertieCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsChasing = false;
}

void ABertieCharacter::StartChase()
{
#if WITH_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, "Started chase");
#endif
	GetCharacterMovement()->MaxWalkSpeed = ChaseSpeed;
	GetCharacterMovement()->MaxAcceleration = ChaseAcceleration;
	bIsChasing = true;
	OnStartChase();
}

void ABertieCharacter::EndChase()
{
#if WITH_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Ended chase");
#endif
	GetCharacterMovement()->MaxWalkSpeed = WanderingSpeed;
	GetCharacterMovement()->MaxAcceleration = WanderingAcceleration;
	bIsChasing = false;
	OnEndChase();
}

void ABertieCharacter::CatchPlayer()
{

}

bool ABertieCharacter::GetChaseState() const
{
	return bIsChasing;
}

// Called when the game starts or when spawned
void ABertieCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABertieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsChasing)
		return;

}

// Called to bind functionality to input
void ABertieCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

