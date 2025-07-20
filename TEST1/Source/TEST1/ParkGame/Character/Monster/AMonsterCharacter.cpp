#include "AMonsterCharacter.h"

AMonsterCharacter::AMonsterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMonsterCharacter::BeginPlay()
{
	Super::BeginPlay();

	// AI 초기 타겟팅 로직 가능
}