// Fill out your copyright notice in the Description page of Project Settings.

#include "MyChooseNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "MyPatrolRouteComponent.h"



EBTNodeResult::Type UMyChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get patrol route
	APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn();
	UMyPatrolRouteComponent* PatrolRouteComp = AIPawn->FindComponentByClass<UMyPatrolRouteComponent>();
	if (!ensure(PatrolRouteComp)) { return EBTNodeResult::Failed; }

	// Get patrol points and warn if it's empty
	TArray<AActor*> PatrolPoints = PatrolRouteComp->GetPatrolPoints();
	if(PatrolPoints.Num() < 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Guard %s is missing patrol points"), *AIPawn->GetName());
		return EBTNodeResult::Failed; 
	}

	// Set next waypoint
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle index
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % PatrolPoints.Num());

	return EBTNodeResult::Succeeded;
}
