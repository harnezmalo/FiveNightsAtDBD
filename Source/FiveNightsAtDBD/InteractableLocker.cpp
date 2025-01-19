#include "InteractableLocker.h"

#include "GregCharacter.h"
#include "InteractibleComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"

AInteractableLocker::AInteractableLocker()
{
    PrimaryActorTick.bCanEverTick = false;
    LinkedLocker = nullptr;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
    RootComponent = BoxComponent;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Locker mesh"));
    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    InteractibleComponent = CreateDefaultSubobject<UInteractibleComponent>(TEXT("Interaction Component"));

    SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Teleport Location"));
}

void AInteractableLocker::TeleportToLinkedLocker(ACharacter* Greg)
{
    if (LinkedLocker && Greg)
    {
        FVector TargetLocation = LinkedLocker->SceneComponent->GetComponentLocation();
        Greg->SetActorLocation(TargetLocation);
        if (AGregCharacter* gchar = Cast<AGregCharacter>(Greg))
            gchar->OnTeleport();

#if WITH_EDITOR
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Teleported to linked locker"));
#endif
    }
#if WITH_EDITOR
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("No linked locker available"));
    }
#endif
}