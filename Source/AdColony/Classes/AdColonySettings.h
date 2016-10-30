
#pragma once

#include "AdColonySettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UAdColonySettings : public UObject
{
	GENERATED_BODY()
	
public:
	UAdColonySettings(const FObjectInitializer& ObjectInitializer);
	
	// SDK Ids

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "App Id"))
	FString AppId;

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "Zone Id"))
	FString ZoneId;

};
