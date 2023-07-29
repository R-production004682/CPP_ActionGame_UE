#pragma once

#include "DrawDebugHelpers.h"


//球体を描画するマクロ。
#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld() ,Location , 25.f , 12 , FColor::Purple , true);

//1フレームのみ球体を描画するマクロ。
#define DRAW_SPHERE_SingleFrame(Location) if(GetWorld()) DrawDebugSphere(GetWorld() ,Location , 25.f , 12 , FColor::Purple , false , -1.f);

//-------------------

//Playerから一定距離のLineを描画するマクロ。
#define DRAW_LINE(StartLocation , EndLocation) if(GetWorld()) DrawDebugLine(GetWorld() , StartLocation , EndLocation , FColor::Red , true , -1.f , 0 , 1.f);

//-------------------


//ベクトルの始点と終点の位置を見やすく描画するマクロ。
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld() , Location , 15.f , FColor::Red , true);

//1フレームのみ始点と終点を描画するマクロ。
#define DRAW_POINT_SingleFrame(Location) if(GetWorld()) DrawDebugPoint(GetWorld() , Location , 15.f , FColor::Red , false , -1.f);


//-------------------

//ベクトルの描画と、終点に点を描画するマクロ。
#define DRAW_VECTOR(StartLocation , EndLocation) if(GetWorld()) {\
																	DrawDebugLine (GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
																	DrawDebugPoint(GetWorld(),   EndLocation,		 15.f, FColor::Red, true);\
																}

//ベクトルの描画と、終点に点を描画するマクロ。
#define DRAW_VECTOR_SingleFrame(StartLocation , EndLocation) if(GetWorld()) {\
																				DrawDebugLine (GetWorld(), StartLocation, EndLocation, FColor::Red, false , -1.f, 0, 1.f); \
																				DrawDebugPoint(GetWorld(),   EndLocation,		 15.f, FColor::Red, false , -1.f);\
																			}


