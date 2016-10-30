
#include "AdColonyPrivatePCH.h"
#include "AdColonySettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogAdColony);

#define LOCTEXT_NAMESPACE "AdColony"

class FAdColony : public IAdColony
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FAdColony, AdColony )

void FAdColony::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "AdColony",
										 LOCTEXT("RuntimeSettingsName", "AdColony"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the AdColony plugin"),
										 GetMutableDefault<UAdColonySettings>()
										 );
	}

#if PLATFORM_ANDROID
	UAdColonyFunctions::InitJavaFunctions();
#endif
}


void FAdColony::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
