#include "ABaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequin_UE4/Meshes/SK_Mannequin.SK_Mannequin'"));

	if (mesh.Succeeded())
		GetMesh()->SetSkeletalMesh(mesh.Object);

	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	if (UCharacterMovementComponent* Movement = GetCharacterMovement())
	{
		Movement->bOrientRotationToMovement = true;
		Movement->RotationRate = FRotator(0.f, 720.f, 0.f);
	}

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
}
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bHasTarget) return;

	FVector ToTarget = TargetLocation - GetActorLocation();
	ToTarget.Z = 0.f;

	if (ToTarget.Size() < StopDistance)
	{
		bHasTarget = false;
		GetCharacterMovement()->StopMovementImmediately();
		return;
	}

	FRotator TargetRot = ToTarget.Rotation();
	FRotator NewRot = FMath::RInterpTo(GetActorRotation(), TargetRot, DeltaTime, 10.f);
	SetActorRotation(NewRot);

	FVector MoveDir = ToTarget.GetSafeNormal();
	AddMovementInput(MoveDir, 1.0f);
}

void ABaseCharacter::SetTargetLocation(const FVector& Location)
{
	TargetLocation = Location;
	bHasTarget = true;
}
//// Fill out your copyright notice in the Description page of Project Settings.
//
//
//#include "ABaseCharacter.h"
//#include "UObject/ConstructorHelpers.h"
//#include "Camera/CameraComponent.h"
//#include "Components/DecalComponent.h"
//#include "Components/CapsuleComponent.h"
//#include "Engine/ObjectLibrary.h"
//#include "GameFramework/CharacterMovementComponent.h"
//#include "GameFramework/PlayerController.h"
//#include "GameFramework/SpringArmComponent.h"
//#include "Materials/Material.h"
//#include "Engine/World.h"
//#include "TEST1/ParkGame/System/MyAssetManager.h"
//
//// Sets default values
//ABaseCharacter::ABaseCharacter()
//{
// 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequin_UE4/Meshes/SK_Mannequin.SK_Mannequin'"));
//
//	if (mesh.Succeeded())//	// Don't rotate character to camera direction
//	bUseControllerRotationPitch = false;
//	bUseControllerRotationYaw = false;
//	bUseControllerRotationRoll = false;
//		GetMesh()->SetSkeletalMesh(mesh.Object);
//
//	// Set size for player capsule
//	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
//

//
//	// Configure character movement
//	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
//	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
//	GetCharacterMovement()->bConstrainToPlane = true;
//	GetCharacterMovement()->bSnapToPlaneAtStart = true;
//
//	// Create a camera boom...
//	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
//	CameraBoom->SetupAttachment(RootComponent);
//	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
//	CameraBoom->TargetArmLength = 800.f;
//	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
//	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level
//
//	// Create a camera...
//	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
//	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
//	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
//
//	// Activate ticking in order to update the cursor every frame.
//	PrimaryActorTick.bCanEverTick = true;
//	PrimaryActorTick.bStartWithTickEnabled = true;
//
//	if (UCharacterMovementComponent* Movement = GetCharacterMovement())
//	{
//		Movement->bOrientRotationToMovement = true;
//		Movement->RotationRate = FRotator(0.f, 720.f, 0.f);
//	}
//}
//
//// Called when the game starts or when spawned
//void ABaseCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//
//}
//
//// Called every frame
//void ABaseCharacter::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	if (!bHasTarget)
//		return;
//
//	FVector ToTarget = TargetLocation - GetActorLocation();
//	ToTarget.Z = 0.f;
//
//	float distance = ToTarget.Size();
//
//	if (distance < StopDistance)
//	{
//		bHasTarget = false;
//		GetCharacterMovement()->StopMovementImmediately();
//		return;
//	}
//
//	// 회전 처리
//	FRotator TargetRot = ToTarget.Rotation();
//	FRotator NewRot = FMath::RInterpTo(GetActorRotation(), TargetRot, DeltaTime, 10.f);
//
//	// 이동 처리
//	FVector MoveDir = ToTarget.GetSafeNormal();
//	AddMovementInput(MoveDir, 1.0f);
//}
//
//// Called to bind functionality to input
//void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}
//
//void ABaseCharacter::SetTargetLocation(const FVector& Location)
//{
//	TargetLocation = Location;
//	bHasTarget = true;
//}
//


