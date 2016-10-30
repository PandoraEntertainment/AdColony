
#pragma once

#include "AdColonyFunctions.generated.h"


UCLASS(NotBlueprintable)
class UAdColonyFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif


	UFUNCTION(BlueprintCallable, meta = (Keywords = "AdColony ad advertising video"), Category = "AdColony|Rewarded Video")
	static void AdColonyShowV4VCReward();

	//UFUNCTION(BlueprintPure, meta = (Keywords = "AdColony ad advertising video"), Category = "AdColony|Rewarded Video")
	//static bool AdColonyHasRewardedVideo(FString ZoneId);

};
