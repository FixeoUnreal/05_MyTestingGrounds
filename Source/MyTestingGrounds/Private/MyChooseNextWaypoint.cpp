// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTestingGrounds/Public/MyChooseNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"



EBTNodeResult::Type UMyChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("BABYY!!!"));
	return EBTNodeResult::Succeeded;
}
