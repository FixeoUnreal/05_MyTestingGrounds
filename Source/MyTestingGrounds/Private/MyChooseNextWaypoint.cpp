// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTestingGrounds/Public/MyChooseNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "MyTestingGrounds/Public/MyPatrollingGuard.h"



EBTNodeResult::Type UMyChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get patrol points 
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	AMyPatrollingGuard* Guard = Cast<AMyPatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	TArray<AActor*> PatrolPoints = Guard->PatrolPointsCPP;
	if(PatrolPoints.Num() < 1){ return EBTNodeResult::Succeeded; }

	// Set next waypoint
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle index
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % PatrolPoints.Num());

	return EBTNodeResult::Succeeded;
}
