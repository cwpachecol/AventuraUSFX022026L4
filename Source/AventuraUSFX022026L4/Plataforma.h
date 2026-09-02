// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

class UStaticMeshComponent;

/*
UENUM(BlueprintType)
enum class ETipoPlataforma : uint8
{
	PLATAFORMA_TERRESTRE UMETA(DisplayName = "TERRESTRE"),
	PLATAFORMA_AEREA UMETA(DisplayName = "AEREA"),
	PLATAFORMA_SUBTERRANEA UMETA(DisplayName = "SUBTERRANEA"),
	PLATAFORMA_ACUATICA UMETA(DisplayName = "ACUATICA")
};
*/

enum class ETipoPlataforma
{
	PLATAFORMA_AEREA,
	PLATAFORMA_TERRESTRE,
	PLATAFORMA_SUBTERRANEA,
	PLATAFORMA_ACUATICA
};

UCLASS()
class AVENTURAUSFX022026L4_API APlataforma : public AActor
{
	GENERATED_BODY()
	
public:
	ETipoPlataforma TipoPlataforma;

public:	
	// Sets default values for this actor's properties
	APlataforma();

public:
	UStaticMeshComponent* mallaPlataforma;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector movimientoEjes = FVector(0.0f, 0.0f, 0.0f);
	FVector movimientoLimitesMaximos = FVector(0.0f, 0.0f, 0.0f);
	FVector movimientoLimitesMinimos = FVector(0.0f, 0.0f, 0.0f);
	FVector movimientoVelocidades = FVector(0.0f, 0.0f, 0.0f);
	FVector movimientoDireccion = FVector(0.0f, 0.0f, 0.0f);
	FVector posicionActual = FVector(0.0f, 0.0f, 0.0f);
};
