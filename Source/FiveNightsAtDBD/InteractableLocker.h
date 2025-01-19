#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableLocker.generated.h"

class UInteractibleComponent;
class UBoxComponent;

UCLASS()
class FIVENIGHTSATDBD_API AInteractableLocker : public AActor
{
    GENERATED_BODY()

public:
    AInteractableLocker();

    // Interaction function
    UFUNCTION(BlueprintCallable, Category = "Interaction")
    void TeleportToLinkedLocker(ACharacter* Character);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UStaticMeshComponent> Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UBoxComponent> BoxComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UInteractibleComponent> InteractibleComponent;

private:

    // Linked locker
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction", meta = (AllowPrivateAccess = true))
    TObjectPtr<AInteractableLocker> LinkedLocker;
};
