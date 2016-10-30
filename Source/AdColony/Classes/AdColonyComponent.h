
#pragma once

#include "AdColonyFunctions.h"
#include "AdColonyComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UAdColonyComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	DECLARE_MULTICAST_DELEGATE_OneParam(FAdColonyAdAvailabilityChangedDelegate, bool);

	static FAdColonyAdAvailabilityChangedDelegate DidAdColonyAdAvailabilityChangeDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAdColonyAdAvailabilityChangedDynDelegate, bool, Availability);

	UPROPERTY(BlueprintAssignable)
	FAdColonyAdAvailabilityChangedDynDelegate DidAdColonyAdAvailabilityChange;

	DECLARE_MULTICAST_DELEGATE_OneParam(FAdColonyDidCompleteRewardedVideoDelegate, int32);

	static FAdColonyDidCompleteRewardedVideoDelegate DidAdColonyCompleteRewardedVideoDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAdColonyDidCompleteRewardedVideoDynDelegate, int32, Reward);

	UPROPERTY(BlueprintAssignable)
	FAdColonyDidCompleteRewardedVideoDynDelegate DidAdColonyCompleteRewardedVideo;

	
	void OnRegister() override;
	void OnUnregister() override;
	
private:	


	void DidAdColonyCompleteRewardedVideo_Handler(int Reward) { DidAdColonyCompleteRewardedVideo.Broadcast(Reward); }
	
	void DidAdColonyAdAvailabilityChange_Handler(bool Availability) { DidAdColonyAdAvailabilityChange.Broadcast(Availability); }


};
