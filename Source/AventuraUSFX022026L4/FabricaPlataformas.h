// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaPlataformas.generated.h"

class APlataforma;

UCLASS()
class AVENTURAUSFX022026L4_API AFabricaPlataformas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaPlataformas();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//APlataforma* CrearPlataforma(FVector Posicion, FRotator Rotacion, FVector Escala, UStaticMesh* Mesh, UMaterialInterface* Material);
	APlataforma* CrearPlataforma(int _tipoPlataforma);

};
