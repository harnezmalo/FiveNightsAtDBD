#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableLocker.generated.h"

UCLASS()
class FIVENIGHTSATDBD_API AInteractableLocker : public AActor
{
    GENERATED_BODY()

public:
    AInteractableLocker();

    // Interaction function
    UFUNCTION(BlueprintCallable, Category = "Interaction")
    void TeleportToLinkedLocker(class AGregCharacter* Character);

private:

    // Linked locker
    UPROPERTY(EditAnywhere, Category = "Interaction")
    AInteractableLocker* LinkedLocker;
};
