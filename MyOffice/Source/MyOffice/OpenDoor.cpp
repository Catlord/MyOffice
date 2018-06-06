// Copyright Benoit Carde 2018 - box@nantes-interactive.fr

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if ((PressurePlate != nullptr) && (ActorThatOpens != nullptr))
	{
		if (PressurePlate->IsOverlappingActor(ActorThatOpens))
		{
			OpenDoor();
		}
	}
	/*
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) {
	OpenDoor();
	}
	*/
}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();

	FRotator NewRotation = FRotator(0.f, -90.f, 0.f);

	Owner->SetActorRotation(NewRotation);
	/*
	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjectName, *ObjectPos);
	*/
}



