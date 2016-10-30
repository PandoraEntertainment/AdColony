
#include "AdColonyPrivatePCH.h"


void UAdColonyComponent::OnRegister()
{
	Super::OnRegister();
	
	UAdColonyComponent::DidAdColonyCompleteRewardedVideoDelegate.AddUObject(this, &UAdColonyComponent::DidAdColonyCompleteRewardedVideo_Handler);

	UAdColonyComponent::DidAdColonyAdAvailabilityChangeDelegate.AddUObject(this, &UAdColonyComponent::DidAdColonyAdAvailabilityChange_Handler);

}

void UAdColonyComponent::OnUnregister()
{
	Super::OnUnregister();
	

	UAdColonyComponent::DidAdColonyCompleteRewardedVideoDelegate.RemoveAll(this);

	UAdColonyComponent::DidAdColonyAdAvailabilityChangeDelegate.RemoveAll(this);
}


UAdColonyComponent::FAdColonyDidCompleteRewardedVideoDelegate UAdColonyComponent::DidAdColonyCompleteRewardedVideoDelegate;

UAdColonyComponent::FAdColonyAdAvailabilityChangedDelegate UAdColonyComponent::DidAdColonyAdAvailabilityChangeDelegate;
