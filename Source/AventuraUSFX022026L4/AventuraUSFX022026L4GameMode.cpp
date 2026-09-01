// Copyright Epic Games, Inc. All Rights Reserved.

#include "AventuraUSFX022026L4GameMode.h"
#include "AventuraUSFX022026L4Pawn.h"
#include "Plataforma.h"

AAventuraUSFX022026L4GameMode::AAventuraUSFX022026L4GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AAventuraUSFX022026L4Pawn::StaticClass();
}

void AAventuraUSFX022026L4GameMode::BeginPlay()
{
	Super::BeginPlay();

	FRotator Rotacion = FRotator(0.0f, 0.0f, 0.0f);
	FVector SpawnLocation = FVector(-950.0f, 50.0f, 200.0f);


	UWorld* World = GetWorld();

	for (int i = 0; i < 10; i++) {
		SpawnLocation = FVector(FMath::RandRange(-1500.0f, 1500.0f), FMath::RandRange(-1500.0f, 1500.0f), FMath::RandRange(50.0f, 1000.0f));
		if (World != nullptr)
		{
			APlataforma* plataformaActual = World->SpawnActor<APlataforma>(SpawnLocation, Rotacion);
			aPlataformas.Add(plataformaActual);
		}
	}

	GetWorldTimerManager().SetTimer(TimerEliminarPlataforma, this, &AAventuraUSFX022026L4GameMode::EliminarPlataforma, 0.3 , true);

	/*
	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 5; j++) {
			SpawnLocation = FVector(-950.0f + (i * 200.0f), 50.0f + (j * 200.0f), 200.0f);
			if (World != nullptr)
			{
				World->SpawnActor<APlataforma>(SpawnLocation, Rotacion);
			
			}
		}
	}

	*/

}

void AAventuraUSFX022026L4GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAventuraUSFX022026L4GameMode::EliminarPlataforma()
{
	int32 Indice = FMath::RandRange(0, 200);


	if (aPlataformas.IsValidIndex(Indice))
	{
		if (IsValid(aPlataformas[Indice]))
		{
			aPlataformas[Indice]->Destroy();

			aPlataformas[Indice] = nullptr;
		}
	}

}

