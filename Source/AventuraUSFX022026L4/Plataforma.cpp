// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));

	// Create mesh component for the projectile sphere
	mallaPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPlataforma"));
	mallaPlataforma->SetStaticMesh(PlataformaMeshAsset.Object);
	mallaPlataforma->SetupAttachment(RootComponent);
	//mallaPlataforma->BodyInstance.SetCollisionProfileName("Projectile");
	//mallaPlataforma->OnComponentHit.AddDynamic(this, &AAventuraUSFX022026L4Projectile::OnHit);		// set up a notification for when this component hits something
	RootComponent = mallaPlataforma;

	ZMax = 800.0f;
	ZMin = 200.0f;
	Velocidad = 100.0f;
	Signo = 1.0f;

}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ZActual = GetActorLocation().Z;

	if (ZActual >= ZMax) {
		Signo = -1.0f;
	}
	else if (ZActual <= ZMin) {
		Signo = 1.0f;
	}

	FVector NuevaUbicacion = GetActorLocation();
	NuevaUbicacion.Z += Velocidad * Signo * DeltaTime;
	SetActorLocation(NuevaUbicacion);
}

