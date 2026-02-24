#ifndef _USERSETTINGS_H_
#define _USERSETTINGS_H_

#include <QSettings>
#include <QString>
#include <QAppPreferences/QAppPreferences.h>

#if !defined(DLL_DECL_SPEC)
#define DLL_DECL_SPEC
#endif

// Default base app settings to allow user to modify them easily before InitBaseSettings()
struct DLL_DECL_SPEC UserSettingsDefaults
{
    QString ShodanApiKey = "";
};

struct DLL_DECL_SPEC UserSettings
{
    /// TODO: Somehow the widgets (that are used to manage the settings for UI apps) shall be moved outside, to keep this base settings compatible with non-widget apps

    /// Register other global settings (AFTER app settings are initialized)
    static void Init(const UserSettingsDefaults &defaultSettings = UserSettingsDefaults());

    /// Pointers to the settings handlers to allow user to modify these settings easily
    static QAppPreferenceInfo *ShodanApiKey;
};


#endif // _USERSETTINGS_H_
