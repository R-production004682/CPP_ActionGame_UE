// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class ACTIONGAME_CPP_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "Sin Parametor")
		float Amplitude = 0.25f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "Sin Parametor")
		float TimeConstant = 5.f;


	UFUNCTION(BlueprintPure)
	float TransformSin();

	UFUNCTION(BlueprintPure)
	float TransformCos();


	template<typename T>
	T Avg(T First, T Second);


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float RunningTime;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;


};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return T(First + Second) / 2;
}
