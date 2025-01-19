#include "GregCharacter.h"
#include "InteractableLocker.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"

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
    DetectLocker();
}

void AGregCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind interaction function
    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AGregCharacter::InteractWithLocker);
}

void AGregCharacter::InteractWithLocker()
{
    if (CurrentLocker)
    {
        CurrentLocker->TeleportToLinkedLocker(this);
    }
}

void AGregCharacter::DetectLocker()
{
    FVector Start = GetActorLocation();
    FVector ForwardVector = GetActorForwardVector();
    FVector End = Start + (ForwardVector * InteractionRange);

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params);

    if (bHit && HitResult.GetActor())
    {
        AInteractableLocker* Locker = Cast<AInteractableLocker>(HitResult.GetActor());
        if (Locker)
        {
            CurrentLocker = Locker;
            return;
        }
    }

    CurrentLocker = nullptr;
}