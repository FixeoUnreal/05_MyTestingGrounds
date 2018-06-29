// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyMannequin.generated.h"

UCLASS()
class MYTESTINGGROUNDS_API AMyMannequin : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FP_Camera;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	class USkeletalMeshComponent* Mesh1P;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	class AMyGun* Gun;

public:
	// Sets default values for this character's properties
	AMyMannequin();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void PullTrigger();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<class AMyGun> GunBlueprint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	
};
