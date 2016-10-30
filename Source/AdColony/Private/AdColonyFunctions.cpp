
#include "AdColonyPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;

//DECLARE_JAVA_METHOD(AndroidThunkJava_AdColony_HasRewardedVideo);
DECLARE_JAVA_METHOD(AndroidThunkJava_AdColony_ShowV4VCReward);


void UAdColonyFunctions::InitJavaFunctions()
{
	//INIT_JAVA_METHOD(AndroidThunkJava_AdColony_HasRewardedVideo, "(Ljava/lang/String;)Z");
	//INIT_JAVA_METHOD(AndroidThunkJava_AdColony_ShowV4VCReward, "(Ljava/lang/String;)V");
	INIT_JAVA_METHOD(AndroidThunkJava_AdColony_ShowV4VCReward, "()V");


}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeDidAdColonyAdAvailabilityChange(boolean availability);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeDidAdColonyAdAvailabilityChange(JNIEnv* jenv, jobject thiz, jboolean availability)
{
	

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UAdColonyComponent::DidAdColonyAdAvailabilityChangeDelegate.Broadcast(availability);
		UE_LOG(LogAndroid, Warning, TEXT("DidAdColonyAdAvailabilityChange\n"));
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeAdColonyDidCompleteRewardedVideo(int reward);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeAdColonyDidCompleteRewardedVideo(JNIEnv* jenv, jobject thiz, jint reward)
{
	

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UAdColonyComponent::DidAdColonyCompleteRewardedVideoDelegate.Broadcast(reward);
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


#endif



void UAdColonyFunctions::AdColonyShowV4VCReward() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		//jstring ZoneIdArg = Env->NewStringUTF(TCHAR_TO_UTF8(*ZoneId));

		//FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AdColony_ShowV4VCReward, ZoneIdArg);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AdColony_ShowV4VCReward);

		//Env->DeleteLocalRef(ZoneIdArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method AdColonyShowV4VCReward\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

/**

bool UAdColonyFunctions::AdColonyHasRewardedVideo(FString ZoneId) {

#if PLATFORM_IOS
	
#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring ZoneIdArg = Env->NewStringUTF(TCHAR_TO_UTF8(*ZoneId));

		bool ret = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AdColony_HasRewardedVideo, ZoneIdArg);

		Env->DeleteLocalRef(ZoneIdArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method AdColonyHasRewardedVideo\n"));

		return ret;
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif

	return false;
}
*/