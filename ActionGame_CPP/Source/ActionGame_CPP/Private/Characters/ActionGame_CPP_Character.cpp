// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ActionGame_CPP_Character.h"
#include  "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AActionGame_CPP_Character::AActionGame_CPP_Character()
{
	PrimaryActorTick.bCanEverTick = true;

	//回転しないようにしておく
	bUseControllerRotationYaw   = false; 
	bUseControllerRotationRoll  = false;
	bUseControllerRotationPitch = false;

	//キャラクターを入力軸方向に回転させる
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	//回転するスピード
	GetCharacterMovement()->RotationRate = FRotator(0.f, 0.f, 280.f);

	//最大移動速度
	GetCharacterMovement()->MaxWalkSpeed = 150.f;



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

	PlayerInputComponent->BindAxis(FName(TEXT("MoveForward")) , this , &AActionGame_CPP_Character::MoveForward);
	PlayerInputComponent->BindAxis(FName(TEXT("MoveRight"))	  , this , &AActionGame_CPP_Character::MoveRight);
	PlayerInputComponent->BindAxis(FName(TEXT("Turn"))		  , this , &AActionGame_CPP_Character::Turn);
	PlayerInputComponent->BindAxis(FName(TEXT("LookUp"))	  , this , &AActionGame_CPP_Character::LookUp);


}

void AActionGame_CPP_Character::MoveForward(float Value)
{
	if (Controller && Value != 0.f)
	{
	
		// カメラの方向を基準にしたローカル移動方向を計算
		const FRotator ControlRotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const FRotator CameraRotation = Camera->GetComponentRotation();
		const FRotator CameraYawRotation(0.f, CameraRotation.Yaw, 0.f);
		const FVector CameraDirection = FRotationMatrix(CameraYawRotation).GetUnitAxis(EAxis::X);


		AddMovementInput(CameraDirection , Value);
	}
}

void AActionGame_CPP_Character::MoveRight(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator ControlRotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		const FRotator CameraRotation = Camera->GetComponentRotation();
		const FRotator CameraYawRotation(0.f, CameraRotation.Yaw, 0.f);
		const FVector CameraDirection = FRotationMatrix(CameraYawRotation).GetUnitAxis(EAxis::Y);


		AddMovementInput(CameraDirection , Value);
	}
}



void AActionGame_CPP_Character::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AActionGame_CPP_Character::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}
