#pragma once

#include <stdint.h>

typedef enum OrbisSystemServiceParamId : int32_t
{
    ORBIS_SYSTEM_SERVICE_PARAM_ID_LANG = 1,
    ORBIS_SYSTEM_SERVICE_PARAM_ID_DATE_FORMAT = 2,
    ORBIS_SYSTEM_SERVICE_PARAM_ID_TIME_FORMAT = 3,
    ORBIS_SYSTEM_SERVICE_PARAM_ID_TIME_ZONE = 4,
    ORBIS_SYSTEM_SERVICE_PARAM_ID_SUMMERTIME = 5,
    ORBIS_SYSTEM_SERVICE_PARAM_ID_SYSTEM_NAME = 6,
    ORBIS_SYSTEM_SERVICE_PARAM_ID_GAME_PARENTAL_LEVEL = 7,
    ORBIS_SYSTEM_SERVICE_PARAM_ID_ENTER_BUTTON_ASSIGN = 1000
} OrbisSystemServiceParamId;

typedef enum OrbisSystemParamDateFormat : int32_t
{
    ORBIS_SYSTEM_PARAM_DATE_FORMAT_YYYYMMDD = 0,
    ORBIS_SYSTEM_PARAM_DATE_FORMAT_DDMMYYYY = 1,
    ORBIS_SYSTEM_PARAM_DATE_FORMAT_MMDDYYYY = 2
} OrbisSystemParamDateFormat;

typedef enum OrbisSystemParamTimeFormat : int32_t
{
    ORBIS_SYSTEM_PARAM_TIME_FORMAT_12HOUR = 0,
    ORBIS_SYSTEM_PARAM_TIME_FORMAT_24HOUR = 1
} OrbisSystemParamTimeFormat;

typedef enum OrbisSystemServiceGpuLoadEmulationMode
{
    ORBIS_SYSTEM_SERVICE_GPU_LOAD_EMULATION_MODE_OFF,
    ORBIS_SYSTEM_SERVICE_GPU_LOAD_EMULATION_MODE_NORMAL,
    ORBIS_SYSTEM_SERVICE_GPU_LOAD_EMULATION_MODE_HIGH,
} OrbisSystemServiceGpuLoadEmulationMode;

typedef enum OrbisSystemParamGameParentalLevel : int32_t
{
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_OFF = 0,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL01 = 1,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL02 = 2,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL03 = 3,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL04 = 4,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL05 = 5,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL06 = 6,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL07 = 7,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL08 = 8,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL09 = 9,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL10 = 10,
    ORBIS_SYSTEM_PARAM_GAME_PARENTAL_LEVEL11 = 11
} OrbisSystemParamGameParentalLevel;

typedef enum OrbisSystemParamEnterButtonAssign : int32_t
{
    ORBIS_SYSTEM_PARAM_ENTER_BUTTON_ASSIGN_CIRCLE = 0,
    ORBIS_SYSTEM_PARAM_ENTER_BUTTON_ASSIGN_CROSS = 1
} OrbisSystemParamEnterButtonAssign;

typedef enum OrbisSystemParamLanguage : int32_t
{
    ORBIS_SYSTEM_PARAM_LANG_JAPANESE = 0,
    ORBIS_SYSTEM_PARAM_LANG_ENGLISH_US = 1,
    ORBIS_SYSTEM_PARAM_LANG_FRENCH = 2,
    ORBIS_SYSTEM_PARAM_LANG_SPANISH = 3,
    ORBIS_SYSTEM_PARAM_LANG_GERMAN = 4,
    ORBIS_SYSTEM_PARAM_LANG_ITALIAN = 5,
    ORBIS_SYSTEM_PARAM_LANG_DUTCH = 6,
    ORBIS_SYSTEM_PARAM_LANG_PORTUGUESE_PT = 7,
    ORBIS_SYSTEM_PARAM_LANG_RUSSIAN = 8,
    ORBIS_SYSTEM_PARAM_LANG_KOREAN = 9,
    ORBIS_SYSTEM_PARAM_LANG_CHINESE_T = 10,
    ORBIS_SYSTEM_PARAM_LANG_CHINESE_S = 11,
    ORBIS_SYSTEM_PARAM_LANG_FINNISH = 12,
    ORBIS_SYSTEM_PARAM_LANG_SWEDISH = 13,
    ORBIS_SYSTEM_PARAM_LANG_DANISH = 14,
    ORBIS_SYSTEM_PARAM_LANG_NORWEGIAN = 15,
    ORBIS_SYSTEM_PARAM_LANG_POLISH = 16,
    ORBIS_SYSTEM_PARAM_LANG_PORTUGUESE_BR = 17,
    ORBIS_SYSTEM_PARAM_LANG_ENGLISH_GB = 18,
    ORBIS_SYSTEM_PARAM_LANG_TURKISH = 19,
    ORBIS_SYSTEM_PARAM_LANG_SPANISH_LA = 20,
    ORBIS_SYSTEM_PARAM_LANG_ARABIC = 21,
    ORBIS_SYSTEM_PARAM_LANG_FRENCH_CA = 22,
    ORBIS_SYSTEM_PARAM_LANG_CZECH = 23,
    ORBIS_SYSTEM_PARAM_LANG_HUNGARIAN = 24,
    ORBIS_SYSTEM_PARAM_LANG_GREEK = 25,
    ORBIS_SYSTEM_PARAM_LANG_ROMANIAN = 26,
    ORBIS_SYSTEM_PARAM_LANG_THAI = 27,
    ORBIS_SYSTEM_PARAM_LANG_VIETNAMESE = 28,
    ORBIS_SYSTEM_PARAM_LANG_INDONESIAN = 29
} OrbisSystemParamLanguage;

typedef struct OrbisSystemServiceEvent 
{
	OrbisSystemServiceEventType	eventType;
	union 
  {
		char param[8192];

		struct 
    {
			char source[1024];
			union 
      {
				char arg[4096];
				char url[4096];
			};
		} urlOpen;

		struct 
    {
			uint32_t size;
			uint8_t arg[8188];
		} launchApp;

		struct 
    {
			uint32_t size;
			uint8_t arg[2020];
		} appLaunchLink;

		struct 
    {
			int32_t userId;
			char eventId[37];
			char bootArgument[7169];
		} joinEvent;

		struct 
    {
			int32_t userId;
			uint32_t npServiceLabel;
			uint8_t reserved[8184];
		} serviceEntitlementUpdate;

		uint8_t	reserved[8192];
	} data;
} OrbisSystemServiceEvent;

// Credit: LightningMods
enum LaunchApp_Flag
{
    LaunchApp_None = 0,
    LaunchApp_SkipLaunch = 1,
    LaunchApp_SkipResume = 1,
    LaunchApp_SkipSystemUpdate = 2,
    LaunchApp_RebootPatchInstall = 4,
    LaunchApp_VRMode = 8,
    LaunchApp_NonVRMode = 16
};

typedef struct _LncAppParam
{
    uint32_t size;
    uint32_t user_id;
    uint32_t app_opt;
    uint64_t crash_report;
    enum LaunchApp_Flag LaunchAppCheck_flag;
}
LncAppParam;
