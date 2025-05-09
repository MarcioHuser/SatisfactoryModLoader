// This file has been automatically generated by the Unreal Header Implementation tool

#include "Tests/FGGameplayTest.h"

FFGGameplayTestResult::FFGGameplayTestResult(){ }
#if WITH_EDITORONLY_DATA
#endif 
UFGGameplayTest::UFGGameplayTest() : Super() {
	this->mDisplayName = INVTEXT("");
	this->mMaximumTestDuration = 60.0;
	this->TestMapOverride = nullptr;
	this->TestMapOptionsOverride = TEXT("");
	this->mTestState = EFGGameplayTestState::None;
	this->mTestResult.TestResult = EFGGameplayTestResult::Undetermined;
}
UWorld* UFGGameplayTest::GetWorld() const{ return nullptr; }
FPrimaryAssetId UFGGameplayTest::GetPrimaryAssetId() const{ return FPrimaryAssetId(); }
AFGTestManager* UFGGameplayTest::GetTestManager() const{ return nullptr; }
EFGGameplayTestState UFGGameplayTest::GetGameplayTestState() const{ return EFGGameplayTestState(); }
FFGGameplayTestResult UFGGameplayTest::GetGameplayTestResult() const{ return FFGGameplayTestResult(); }
void UFGGameplayTest::AddTestActor(AActor* testActor){ }
void UFGGameplayTest::Internal_TransitionToState(EFGGameplayTestState newState){ }
void UFGGameplayTest::Internal_Tick(float dt){ }
void UFGGameplayTest::DrawDebug(UCanvas* canvas){ }
void UFGGameplayTest::AddMessage(EFGGameplayTestMessageLevel messageLevel, const FText& message, const FString& context , int32 stackOffset){ }
void UFGGameplayTest::K2_AddMessage(EFGGameplayTestMessageLevel messageLevel, FText message, const FString& context){  }
void UFGGameplayTest::AddInfo(FText message){  }
void UFGGameplayTest::AddWarning(FText message){  }
void UFGGameplayTest::AddError(FText message){  }FString UFGGameplayTest::CaptureStackTraceContext(int32 StackOffset){ return FString(); }
FString UFGGameplayTest::CaptureScriptContext(const FFrame& Stack){ return FString(); }
FColor UFGGameplayTest::GetDebugColorForLevel(EFGGameplayTestMessageLevel level){ return FColor(); }
void UFGGameplayTest::OnTestStarted(){ }
void UFGGameplayTest::OnTestFinished(){ }
void UFGGameplayTest::OnTestEnded(){ }
void UFGGameplayTest::TickRunningTest(float dt){ }
void UFGGameplayTest::FinishTest(EFGGameplayTestResult testResult){ }
void UFGGameplayTest::FailTest(FText errorMessage){  }
void UFGGameplayTest::PassTest(){  }
void UFGGameplayTest::AddTestMetadata(const FString& metadataKey, const FString& metadataValue){ }
void UFGGameplayTest::KillTestSpawnedActors(){ }
bool UFGGameplayTest::HasAnyErrorMessagesInLog() const{ return bool(); }

DEFINE_FUNCTION(UFGGameplayTest::execK2_AddMessage) {
	PARAM_PASSED_BY_VAL(messageLevel, FEnumProperty, EFGGameplayTestMessageLevel);
	PARAM_PASSED_BY_REF(message, FStructProperty, FText);
	PARAM_PASSED_BY_REF(context, FStrProperty, FString);
	PARAM_PASSED_BY_REF(stackOffset, FIntProperty, int32);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_NATIVE_END;
}

DEFINE_FUNCTION(UFGGameplayTest::execAddInfo) {
	PARAM_PASSED_BY_REF(message, FStructProperty, FText);
	PARAM_PASSED_BY_REF(context, FStrProperty, FString);
	PARAM_PASSED_BY_REF(stackOffset, FIntProperty, int32);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_NATIVE_END;
}

DEFINE_FUNCTION(UFGGameplayTest::execAddWarning) {
	PARAM_PASSED_BY_REF(message, FStructProperty, FText);
	PARAM_PASSED_BY_REF(context, FStrProperty, FString);
	PARAM_PASSED_BY_REF(stackOffset, FIntProperty, int32);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_NATIVE_END;
}

DEFINE_FUNCTION(UFGGameplayTest::execAddError) {
	PARAM_PASSED_BY_REF(message, FStructProperty, FText);
	PARAM_PASSED_BY_REF(context, FStrProperty, FString);
	PARAM_PASSED_BY_REF(stackOffset, FIntProperty, int32);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_NATIVE_END;
}

DEFINE_FUNCTION(UFGGameplayTest::execFailTest) {
	PARAM_PASSED_BY_REF(message, FStructProperty, FText);
	PARAM_PASSED_BY_REF(context, FStrProperty, FString);
	PARAM_PASSED_BY_REF(stackOffset, FIntProperty, int32);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_NATIVE_END;
}
