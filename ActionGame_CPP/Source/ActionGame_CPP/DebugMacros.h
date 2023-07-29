#pragma once

#include "DrawDebugHelpers.h"


//���̂�`�悷��}�N���B
#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld() ,Location , 25.f , 12 , FColor::Purple , true);

//1�t���[���̂݋��̂�`�悷��}�N���B
#define DRAW_SPHERE_SingleFrame(Location) if(GetWorld()) DrawDebugSphere(GetWorld() ,Location , 25.f , 12 , FColor::Purple , false , -1.f);

//-------------------

//Player�����苗����Line��`�悷��}�N���B
#define DRAW_LINE(StartLocation , EndLocation) if(GetWorld()) DrawDebugLine(GetWorld() , StartLocation , EndLocation , FColor::Red , true , -1.f , 0 , 1.f);

//-------------------


//�x�N�g���̎n�_�ƏI�_�̈ʒu�����₷���`�悷��}�N���B
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld() , Location , 15.f , FColor::Red , true);

//1�t���[���̂ݎn�_�ƏI�_��`�悷��}�N���B
#define DRAW_POINT_SingleFrame(Location) if(GetWorld()) DrawDebugPoint(GetWorld() , Location , 15.f , FColor::Red , false , -1.f);


//-------------------

//�x�N�g���̕`��ƁA�I�_�ɓ_��`�悷��}�N���B
#define DRAW_VECTOR(StartLocation , EndLocation) if(GetWorld()) {\
																	DrawDebugLine (GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
																	DrawDebugPoint(GetWorld(),   EndLocation,		 15.f, FColor::Red, true);\
																}

//�x�N�g���̕`��ƁA�I�_�ɓ_��`�悷��}�N���B
#define DRAW_VECTOR_SingleFrame(StartLocation , EndLocation) if(GetWorld()) {\
																				DrawDebugLine (GetWorld(), StartLocation, EndLocation, FColor::Red, false , -1.f, 0, 1.f); \
																				DrawDebugPoint(GetWorld(),   EndLocation,		 15.f, FColor::Red, false , -1.f);\
																			}


