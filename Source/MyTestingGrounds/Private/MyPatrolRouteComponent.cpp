// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTestingGrounds/Public/MyPatrolRouteComponent.h"



TArray<AActor*> UMyPatrolRouteComponent::GetPatrolPoints() const
{
	return PatrolPointsCPP;
}


