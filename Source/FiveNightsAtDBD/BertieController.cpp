// Fill out your copyright notice in the Description page of Project Settings.


#include "BertieController.h"
#include <Perception/AIPerceptionComponent.h>
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

ABertieController::ABertieController(const FObjectInitializer& ObjectInitializer)
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
	/*static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("/Script/AIModule.BehaviorTree'/Game/Game/Blueprint/Bertie/BT_Bertie.BT_Bertie'"));

	if(obj.Succeeded())
	{
		BehaviorTree = obj.Object;
	}*/

	Blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BTComponent"));
}

void ABertieController::OnPerception(AActor* Actor, FAIStimulus Stimulus)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, "Sensed something");
	SetFocus(Stimulus.WasSuccessfullySensed() ? Actor : nullptr);
}

void ABertieController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ABertieController::OnPerception);
	if(Blackboard)
	{
		Blackboard->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	}
}

void ABertieController::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (Player != nullptr)
	{
		GetBlackboardComponent()->SetValueAsObject("Target", Player);
	}
#if WITH_EDITOR
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, "Player invalid");
	}
#endif

	RunBehaviorTree(BehaviorTree);
	BehaviorTreeComponent->StartTree(*BehaviorTree);
}
