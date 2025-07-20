#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ABaseCharacter.generated.h"

UCLASS()
class TEST1_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

	virtual void Tick(float DeltaTime) override;
	void SetTargetLocation(const FVector& Location);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float StopDistance = 50.f;

	FVector TargetLocation;
	bool bHasTarget = false;
};

//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/Character.h"
//#include "ABaseCharacter.generated.h"
//
//UCLASS()
//class TEST1_API ABaseCharacter : public ACharacter
//{
//	GENERATED_BODY()
//
//public:	
//	// Sets default values for this character's properties
//	ABaseCharacter();
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//	// Called to bind functionality to input
//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
//
//	void SetTargetLocation(const FVector& Location);
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
//	float MoveSpeed = 600.f;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
//	float StopDistance = 50.f;
//
//private:
//	/** Top down camera */
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
//	class UCameraComponent* TopDownCameraComponent;
//
//	/** Camera boom positioning the camera above the character */
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
//	class USpringArmComponent* CameraBoom;
//
//
//
//	FVector TargetLocation;
//	bool bHasTarget = false;
//};
