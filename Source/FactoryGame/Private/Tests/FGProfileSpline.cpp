// This file has been automatically generated by the Unreal Header Implementation tool

#include "Tests/FGProfileSpline.h"

AFGProfileSpline::AFGProfileSpline() : Super() {
	this->Duration = 0.0;
	this->PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;
	this->PrimaryActorTick.EndTickGroup = ETickingGroup::TG_PrePhysics;
	this->PrimaryActorTick.bTickEvenWhenPaused = false;
	this->PrimaryActorTick.bCanEverTick = true;
	this->PrimaryActorTick.bStartWithTickEnabled = true;
	this->PrimaryActorTick.bAllowTickOnDedicatedServer = true;
	this->PrimaryActorTick.TickInterval = 0.0;
}
void AFGProfileSpline::BeginPlay(){ Super::BeginPlay(); }
void AFGProfileSpline::Tick(float DeltaTime){ Super::Tick(DeltaTime); }
