// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EWS_Inital UMETA(DisplayName = "Inital State"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Dropped UMETA(DisplayName = "Dopped"),

	EWS_MAX UMETA(DisplayName = "DefaultMAX")
};

UCLASS()
class MULTIPLAYERSHOOTER_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:
	AWeapon();

	void ShowPickupWidget(bool bShowWidget);
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndext);

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnyWhere, Category = "Weapon Properties");
	class USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnyWhere, Category = "Weapon Properties");
	class USphereComponent* AreaSphere;

	UPROPERTY(VisibleAnyWhere, Category = "Weapon Properties");
	class UWidgetComponent* PickupWidget;

	UPROPERTY(VisibleAnyWhere);
	EWeaponState WeaponState;

};
