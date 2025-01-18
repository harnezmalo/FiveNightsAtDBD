// Fill out your copyright notice in the Description page of Project Settings.


#include "EvaluateState.h"
#include  "BertieCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UEvaluateState::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const ABertieCharacter* Bertie = Cast<ABertieCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetKey.SelectedKeyName));

	if (!Bertie)
		return false;

	return Bertie->GetChaseState();
}
