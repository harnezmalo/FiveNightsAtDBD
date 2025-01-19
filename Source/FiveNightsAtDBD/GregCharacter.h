#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GregCharacter.generated.h"

class UInputComponent;
class UInteractibleComponent;

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
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

    // Interaction function
    UFUNCTION(BlueprintCallable, Category = "Interaction")
    void Interact();

    UFUNCTION(BlueprintImplementableEvent, DisplayName = "On Teleport")
    void OnTeleport();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<AActor> FoodHeld;

private:
    // The locker currently in range
    UPROPERTY(VisibleAnywhere, Category = "Interaction")
    TObjectPtr<UInteractibleComponent> CurrentInteractable;

    // Function to detect lockers
    UFUNCTION()
    void DetectInteractible();

    // Interaction range
    UPROPERTY(EditAnywhere, Category = "Interaction")
    float InteractionRange = 200.0f;
};