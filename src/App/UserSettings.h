#ifndef _USERSETTINGS_H_
#define _USERSETTINGS_H_

#include <QString>
#include <QCoreApplication>

#include "Singleton.h"

class UserSettings: public Singleton<UserSettings>
{
public:
    QStringList GetUserDataLocationsRel()
    {
        return QStringList( "/user/data");
    }
};

#endif // _USERSETTINGS_H_
