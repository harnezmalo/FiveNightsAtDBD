#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractableLocker.h"
#include "GregCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTeleportEvent);

UCLASS()
class FIVENIGHTSATDBD_API AGregCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AGregCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Interaction function
    UFUNCTION(BlueprintCallable, Category = "Interaction")
    void InteractWithLocker();

    UPROPERTY(BlueprintAssignable)
    FTeleportEvent OnTeleport;

private:
    // The locker currently in range
    class AInteractableLocker* CurrentLocker;

    // Function to detect lockers
    void DetectLocker();

    // Interaction range
    UPROPERTY(EditAnywhere, Category = "Interaction")
    float InteractionRange = 200.0f;
};