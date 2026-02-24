#include "UserSettings.h"

#include <QCoreApplication>
#include <QApplication>
#include <QFileInfo>
#include <QStandardPaths>

// Store pointers to the settings
QAppPreferenceInfo *UserSettings::ShodanApiKey = nullptr;

void UserSettings::Init(const UserSettingsDefaults &defaultSettings)
{
    static bool initialized = false;

    if( initialized )
        return;
    initialized = true;

    // Init misc settings
    uint8_t osintSettsFlags = QAppPreferences::IS_SHOWN_IN_PREFS_GUI | QAppPreferences::IS_PERSISTENT | QAppPreferences::IS_SECURED;
    QAppPreferences *osintSetts = QAppPreferences::inst("OSINT");
    UserSettings::ShodanApiKey = osintSetts->RegisterSetting("Shodan API key", QVariant(defaultSettings.ShodanApiKey), osintSettsFlags);
}


