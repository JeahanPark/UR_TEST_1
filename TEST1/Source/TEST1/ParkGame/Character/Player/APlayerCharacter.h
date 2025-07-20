#pragma once

#include "TEST1/ParkGame/Character/ABaseCharacter.h"
#include "APlayerCharacter.generated.h"

UCLASS()
class TEST1_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* TopDownCamera;
};
