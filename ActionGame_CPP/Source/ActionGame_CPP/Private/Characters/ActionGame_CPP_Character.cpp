// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ActionGame_CPP_Character.h"
#include  "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AActionGame_CPP_Character::AActionGame_CPP_Character()
{
	PrimaryActorTick.bCanEverTick = true;

	//‰ñ“]‚µ‚È‚¢‚æ‚¤‚É‚µ‚Ä‚¨‚­
	bUseControllerRotationYaw   = false; 
	bUseControllerRotationRoll  = false;
	bUseControllerRotationPitch = false;


	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 250.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);
}

void AActionGame_CPP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AActionGame_CPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActionGame_CPP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName(TEXT("MoveRight"))	  , this , &AActionGame_CPP_Character::MoveForward);
	PlayerInputComponent->BindAxis(FName(TEXT("MoveForward")) , this , &AActionGame_CPP_Character::MoveRight);
	PlayerInputComponent->BindAxis(FName(TEXT("Turn"))		  , this , &AActionGame_CPP_Character::Turn);
	PlayerInputComponent->BindAxis(FName(TEXT("LookUp"))	  , this , &AActionGame_CPP_Character::LookUp);


}

void AActionGame_CPP_Character::MoveForward(float Value)
{
	if (Controller && Value != 0.f)
	{
	
		// ƒJƒƒ‰‚Ì•ûŒü‚ðŠî€‚É‚µ‚½ƒ[ƒJƒ‹ˆÚ“®•ûŒü‚ðŒvŽZ
		const FRotator ControlRotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction , Value);
	}
}

void AActionGame_CPP_Character::MoveRight(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator ControlRotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction , Value);
	}
}



void AActionGame_CPP_Character::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AActionGame_CPP_Character::LookUp(float Value)
{
	AddControllerRollInput(Value);
}
