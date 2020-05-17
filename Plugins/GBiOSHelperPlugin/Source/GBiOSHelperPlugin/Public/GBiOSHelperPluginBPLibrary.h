// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GBiOSHelperPluginBPLibrary.generated.h"

/* 
*	iOSHelper Function library class.
*/

DECLARE_DYNAMIC_DELEGATE_OneParam(FGBOpenURLDelegate, bool, bSuccess);

UCLASS()
class UGBiOSHelperPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

    /**
     * Open Mail App
     *
     * @param Email
     * @param Delegate
     */
    UFUNCTION(BlueprintCallable, Category = GBiOSHelper, meta = (Keywords = "GBiOSHelperPlugin"))
    static void OpenEmailApp(FString Email, FGBOpenURLDelegate Delegate);
    
    
    /**
     * Open URL
     *
     * @param URL
     * @param Delegate
     */
    UFUNCTION(BlueprintCallable, Category = GBiOSHelper, meta = (Keywords = "GBiOSHelperPlugin"))
    static void OpenURL(FString URL, FGBOpenURLDelegate Delegate);
    
    
    /**
     * Open WhatsApp app
     *
     * @param Message
     * @param Delegate
     */
    UFUNCTION(BlueprintCallable, Category = GBiOSHelper, meta = (Keywords = "GBiOSHelperPlugin"))
    static void OpenWhatsApp(FString Message, FGBOpenURLDelegate Delegate);
    
    /**
     * Open Twitch app
     *
     * @param Delegate
     */
    UFUNCTION(BlueprintCallable, Category = GBiOSHelper, meta = (Keywords = "GBiOSHelperPlugin"))
    static void OpenTwitchApp(FGBOpenURLDelegate Delegate);
    
    /**
     * Open Twitch channel
     *
     * @param ChannelName
     * @param Delegate
     */
    UFUNCTION(BlueprintCallable, Category = GBiOSHelper, meta = (Keywords = "GBiOSHelperPlugin"))
    static void OpenTwitchChannel(FString ChannelName, FGBOpenURLDelegate Delegate);
    
    /**
     * Open Twitch game directory
     *
     * @param GameName
     * @param Delegate
     */
    UFUNCTION(BlueprintCallable, Category = GBiOSHelper, meta = (Keywords = "GBiOSHelperPlugin"))
    static void OpenTwitchGameDirectory(FString GameName, FGBOpenURLDelegate Delegate);
    
    /**
     * Open a video on Twitch
     *
     * @param VideoID
     * @param Delegate
     */
    UFUNCTION(BlueprintCallable, Category = GBiOSHelper, meta = (Keywords = "GBiOSHelperPlugin"))
    static void OpenTwitchVideo(FString VideoID, FGBOpenURLDelegate Delegate);
    
    
    /**
     * Open Twitch channel activity feed
     *
     * @param ChannelName
     * @param Delegate
     */
    UFUNCTION(BlueprintCallable, Category = GBiOSHelper, meta = (Keywords = "GBiOSHelperPlugin"))
    static void OpenTwitchChannelFeed(FString ChannelName, FGBOpenURLDelegate Delegate);
    
    /**
     * Open Twitch Live Stream Tag
     *
     * @param TagID
     * @param Delegate
     */
    UFUNCTION(BlueprintCallable, Category = GBiOSHelper, meta = (Keywords = "GBiOSHelperPlugin"))
    static void OpenTwitchLiveStreamTag(FString TagID, FGBOpenURLDelegate Delegate);
};
