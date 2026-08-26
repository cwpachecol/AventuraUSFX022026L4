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

	//movimientoEjes = FVector(FMath::RandRange(-1.0f, 1.0f), FMath::RandRange(-1.0f, 1.0f), FMath::RandRange(-1.0f, 1.0f));
	movimientoEjes = FVector(1.0f, 0.0f, 0.0f);
	movimientoLimitesMaximos = FVector(FMath::RandRange(200.0f, 800.0f), FMath::RandRange(200.0f, 800.0f), FMath::RandRange(200.0f, 800.0f));
	movimientoLimitesMinimos = FVector(FMath::RandRange(-800.0f, -200.0f), FMath::RandRange(-800.0f, -200.0f), FMath::RandRange(-800.0f, -200.0f));
	movimientoVelocidades = FVector(FMath::RandRange(50.0f, 200.0f), FMath::RandRange(50.0f, 200.0f), FMath::RandRange(50.0f, 200.0f));
	//movimientoDireccion = FVector(FMath::RandRange(-1.0f, 1.0f), FMath::RandRange(-1.0f, 1.0f), FMath::RandRange(-1.0f, 1.0f));
	movimientoDireccion = FVector(1.0f, 0.0f, 0.0f);



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

	posicionActual = GetActorLocation();


	if (posicionActual.X >= movimientoLimitesMaximos.X || posicionActual.X <= movimientoLimitesMinimos.X) {
		movimientoDireccion.X *= -1.0f;
	}

	if (posicionActual.Y >= movimientoLimitesMaximos.Y || posicionActual.Y <= movimientoLimitesMinimos.Y) {
		movimientoDireccion.Y *= -1.0f;
	}

	if (posicionActual.Z >= movimientoLimitesMaximos.Z || posicionActual.Z <= movimientoLimitesMinimos.Z) {
		movimientoDireccion.Z *= -1.0f;
	}

	FVector posicionNueva = posicionActual + (movimientoDireccion * movimientoVelocidades * DeltaTime);
	SetActorLocation(posicionNueva);

}

