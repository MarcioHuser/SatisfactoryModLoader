// This file has been automatically generated by the Unreal Header Implementation tool

#include "RequestEmitters/FGClientAuthenticationRequester.h"

#include "Networking/FGClientAPIManager.h"

void UFGClientAuthenticationRequester::Response_VerifyAuthenticationToken(FFGServerErrorResponse& ErrorResponse, EPrivilegeLevel MinimumPrivilegeLevel, bool bAutomaticLogin) const {}
void UFGClientAuthenticationRequester::Response_PasswordlessLogin(FFGServerErrorResponse& ErrorResponse, const FString& AuthenticationToken, EPrivilegeLevel LocalMinimumPrivilegeLevel, bool bAutomaticLogin) const {}
void UFGClientAuthenticationRequester::Response_PasswordLogin(FFGServerErrorResponse& ErrorResponse, const FString& AuthenticationToken, EPrivilegeLevel LocalMinimumPrivilegeLevel) const {}
