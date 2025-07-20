#pragma once

#include "TEST1/ParkGame/Character/ABaseCharacter.h"
#include "AMonsterCharacter.generated.h"

UCLASS()
class TEST1_API AMonsterCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AMonsterCharacter();

protected:
	virtual void BeginPlay() override;

	// 추가로 AIController 관련 구성 가능
};