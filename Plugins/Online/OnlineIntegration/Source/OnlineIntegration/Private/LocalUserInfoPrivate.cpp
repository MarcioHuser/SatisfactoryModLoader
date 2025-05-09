// This file has been automatically generated by the Unreal Header Implementation tool

#include "LocalUserInfoPrivate.h"

#include "User/OnlineUserInfoPrivate.h"

void ULocalUserInfoPrivate::SetLoginStatusForBackend(ECommonUserLoginStatus InLoginStatus, UOnlineIntegrationBackend* Backend){ }
void ULocalUserInfoPrivate::SetPresenceJoinability(UE::Online::EUserPresenceJoinability Joinability) const{ }
void ULocalUserInfoPrivate::SetGameSession(USessionInformation* InSession){ }
void ULocalUserInfoPrivate::SetCurrentAuthenticationSequence( UOnlineAuthenticationSequence* AuthenticationSequence){ }
void ULocalUserInfoPrivate::OnLoginStatusChanged(TSharedRef<UE::Online::FAccountInfo> AccountInfo, UOnlineIntegrationBackend* Backend){ }
void ULocalUserInfoPrivate::HandlePresenceUpdated(const UE::Online::FPresenceUpdated& PresenceUpdated, UOnlineIntegrationBackend* Backend){ }
void ULocalUserInfoPrivate::HandleUISessionJoinRequested(const UE::Online::FUISessionJoinRequested& SessionJoinRequested, UOnlineIntegrationBackend* Backend){ }
UOnlineUserBackendLinkPrivate* ULocalUserInfoPrivate::GetBackendPrivate(UOnlineIntegrationBackend* Backend){ return nullptr; }
UOnlineUserInfoPrivate& ULocalUserInfoPrivate::GetOnlineUserInfoPrivate(){ return *NewObject<UOnlineUserInfoPrivate>(); }
void ULocalUserInfoPrivate::QueryGlobalCrossplaySetting(UOnlineIntegrationBackend* Backend){ }
void ULocalUserInfoPrivate::DisplayCrossPlaySystemMessage(UCommonUserSubsystem* userSubsystem){ }
void ULocalUserInfoPrivate::OnPlatformChecksDoneCallback(EPrivilegeResults privilege){ }
