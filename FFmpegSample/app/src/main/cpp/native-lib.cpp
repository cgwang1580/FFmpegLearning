#include <jni.h>
#include <string>

extern "C" {
	#include "libavcodec/version.h"
	#include "libavcodec/avcodec.h"
	#include "libavformat/version.h"
	#include "libavutil/version.h"
	#include "libavfilter/version.h"
	#include "libswresample/version.h"
	#include "libswscale/version.h"
};

#include "LogAndroid.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL
Java_com_chauncy_ffmpegsample_MainActivity_getFFmpegVersion(JNIEnv *env, jobject thiz)
{
	// TODO: implement getFFmpegVersion()
	char strVersion[1024 * 4]{0};
	strcat(strVersion, "libavcodec version: ");
	strcat(strVersion, AV_STRINGIFY(LIBAVCODEC_VERSION));

	strcat(strVersion, "\nlibavformat version: ");
	strcat(strVersion, AV_STRINGIFY(LIBAVFORMAT_VERSION));

	strcat(strVersion, "\nlibavutil version: ");
	strcat(strVersion, AV_STRINGIFY(LIBAVUTIL_VERSION));

	strcat(strVersion, "\nlibavfilter version: ");
	strcat(strVersion, AV_STRINGIFY(LIBAVFILTER_VERSION));

	strcat(strVersion, "\nlibswresample version: ");
	strcat(strVersion, AV_STRINGIFY(LIBSWRESAMPLE_VERSION));

	strcat(strVersion, "\nlibswscale version: ");
	strcat(strVersion, AV_STRINGIFY(LIBSWSCALE_VERSION));

	strcat(strVersion, "\navcodec_configuration: ");
	strcat(strVersion, avcodec_configuration());

	strcat(strVersion, "\navcodec_license: ");
	strcat(strVersion, avcodec_license());

	LOGD("Java_com_chauncy_ffmpegsample_MainActivity_getFFmpegVersion strVersion: %s", strVersion);
	return env->NewStringUTF(strVersion);
}

#ifdef __cplusplus
}
#endif