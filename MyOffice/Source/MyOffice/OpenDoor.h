// Copyright Benoit Carde 2018 - box@nantes-interactive.fr

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYOFFICE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
		float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;
	
		AActor* ActorThatOpens;

	
	/*
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;
	float TriggerMass = 30.f;
	
	

	float LastDoorOpenTime;

	//AActor* ActorThatOpens;
	AActor* Owner = nullptr;
		*/
};
