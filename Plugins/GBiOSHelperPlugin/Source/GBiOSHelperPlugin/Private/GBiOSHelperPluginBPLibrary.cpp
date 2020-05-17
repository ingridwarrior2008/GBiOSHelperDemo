// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GBiOSHelperPluginBPLibrary.h"
#include "GBiOSHelperPlugin.h"

#if PLATFORM_IOS
#include "IOSAppDelegate.h"
#import <UIKit/UIKit.h>
#endif



UGBiOSHelperPluginBPLibrary::UGBiOSHelperPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    
}

void UGBiOSHelperPluginBPLibrary::OpenEmailApp(FString Email, FGBOpenURLDelegate Delegate)
{
    FString MailTo = "mailto:" + Email;
    UGBiOSHelperPluginBPLibrary::OpenURL(MailTo, Delegate);
}

void UGBiOSHelperPluginBPLibrary::OpenWhatsApp(FString Message, FGBOpenURLDelegate Delegate)
{
    FString WhatsAppMessage = "whatsapp://send?text=" + Message;
    UGBiOSHelperPluginBPLibrary::OpenURL(WhatsAppMessage, Delegate);
}

void UGBiOSHelperPluginBPLibrary::OpenTwitchApp(FGBOpenURLDelegate Delegate)
{
    FString TwitchURL = "twitch://open";
    UGBiOSHelperPluginBPLibrary::OpenURL(TwitchURL, Delegate);
}

void UGBiOSHelperPluginBPLibrary::OpenTwitchChannel(FString ChannelName, FGBOpenURLDelegate Delegate)
{
    FString TwitchURL = "twitch://open?stream=" + ChannelName;
    UGBiOSHelperPluginBPLibrary::OpenURL(TwitchURL, Delegate);
}

void UGBiOSHelperPluginBPLibrary::OpenTwitchGameDirectory(FString GameName, FGBOpenURLDelegate Delegate)
{
    FString TwitchURL = "twitch://open?game=" + GameName;
    UGBiOSHelperPluginBPLibrary::OpenURL(TwitchURL, Delegate);
}

void UGBiOSHelperPluginBPLibrary::OpenTwitchVideo(FString VideoID, FGBOpenURLDelegate Delegate)
{
    FString TwitchURL = "twitch://open?video=" + VideoID;
    UGBiOSHelperPluginBPLibrary::OpenURL(TwitchURL, Delegate);
}

void UGBiOSHelperPluginBPLibrary::OpenTwitchChannelFeed(FString ChannelName, FGBOpenURLDelegate Delegate)
{
    FString TwitchURL = "twitch://open?channel=" + ChannelName;
    UGBiOSHelperPluginBPLibrary::OpenURL(TwitchURL, Delegate);
}

void UGBiOSHelperPluginBPLibrary::OpenTwitchLiveStreamTag(FString TagID, FGBOpenURLDelegate Delegate)
{
    FString TwitchURL = "twitch://directory/all/tags/" + TagID;
    UGBiOSHelperPluginBPLibrary::OpenURL(TwitchURL, Delegate);
}


void UGBiOSHelperPluginBPLibrary::OpenURL(FString URL, FGBOpenURLDelegate Delegate)
{
#if PLATFORM_IOS
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:URL.GetNSString()] options:@{} completionHandler:^(BOOL bSuccess) {
        dispatch_async(dispatch_get_main_queue(), ^
                       {
            Delegate.ExecuteIfBound(bSuccess);
        });
    }];
#endif
}
