// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaPlataformas.h"
#include "Plataforma.h"
#include "PlataformaAerea.h"
#include "PlataformaTerrestre.h"

// Sets default values
AFabricaPlataformas::AFabricaPlataformas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaPlataformas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaPlataformas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

APlataforma* AFabricaPlataformas::CrearPlataforma(int _tipoPlataforma)
{
	FVector SpawnLocation = FVector(-500.0f, 100.0f, 150.0f);
	FRotator Rotacion = FRotator(0.0f, 0.0f, 0.0f);

	if (GetWorld() == nullptr)
	{
		return nullptr;
	}

	UWorld* World = GetWorld();

	if (_tipoPlataforma == 0)
	{
		APlataforma* plataformaActual = World->SpawnActor<APlataformaAerea>(SpawnLocation, Rotacion);
		return plataformaActual;
	}
	else if (_tipoPlataforma == 1)
	{
		APlataforma* plataformaActual = World->SpawnActor<APlataformaTerrestre>(SpawnLocation, Rotacion);
		return plataformaActual;
	}
	else {
		return nullptr;
	}
}

