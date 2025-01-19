#include "InteractableLocker.h"
#include "GregCharacter.h"
#include "Engine/Engine.h"

AInteractableLocker::AInteractableLocker()
{
    PrimaryActorTick.bCanEverTick = false;
    LinkedLocker = nullptr;
}

void AInteractableLocker::TeleportToLinkedLocker(AGregCharacter* Greg)
{
    if (LinkedLocker && Greg)
    {
        FVector TargetLocation = LinkedLocker->GetActorLocation();
        Greg->SetActorLocation(TargetLocation);
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Teleported to linked locker"));
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("No linked locker available"));
    }
}