// Fill out your copyright notice in the Description page of Project Settings.


#include "Test01Actor.h"

ATest01Actor::ATest01Actor()
{
}

void ATest01Actor::BeginPlay()
{
	UE_LOG(Test01, Log, TEXT("Hello World"));
}

void ATest01Actor::Tick(float DeltaTime)
{
}
