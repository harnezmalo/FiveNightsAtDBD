#include "GregCharacter.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "InteractibleComponent.h"
#include "Kismet/KismetSystemLibrary.h"

AGregCharacter::AGregCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AGregCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AGregCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Check for lockers in range
    DetectInteractible();
}

void AGregCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind interaction function
    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AGregCharacter::Interact);
}

void AGregCharacter::Interact()
{
    if (CurrentInteractable)
    {
        CurrentInteractable->Interact(this);
    }
}

void AGregCharacter::DetectInteractible()
{
    FVector Start = GetActorLocation();

    TArray<AActor*> actorsHit;
    TArray<AActor*> actorsToIgnore;
    actorsToIgnore.Add(this);
    TArray<TEnumAsByte<EObjectTypeQuery>> objectsFilter;
    objectsFilter.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));

    UKismetSystemLibrary::SphereOverlapActors(GetWorld(), Start, InteractionRange, objectsFilter, nullptr, actorsToIgnore, actorsHit);

    TArray<AActor*> interactibleActors;
    for(auto& Actor : actorsHit)
    {
        if (Cast<UInteractibleComponent>(Actor->GetComponentByClass(UInteractibleComponent::StaticClass())))
            interactibleActors.Add(Actor);
    }

    interactibleActors.Sort([&](const AActor& A, const AActor& B)
    {
        float DistanceA = FVector::Dist(this->GetActorLocation(), A.GetActorLocation());
        float DistanceB = FVector::Dist(this->GetActorLocation(), B.GetActorLocation());
        return DistanceA < DistanceB;
    });

    if (interactibleActors.Num() > 0)
    {
        UInteractibleComponent* InteractibleComponent = Cast<UInteractibleComponent>(interactibleActors[0]->GetComponentByClass(UInteractibleComponent::StaticClass()));
        if(InteractibleComponent)
        {
            CurrentInteractable = InteractibleComponent;
            return;
        }
    }

    CurrentInteractable = nullptr;
}