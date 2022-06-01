#ifndef _CFG_PORTSSCANNER_H_
#define _CFG_PORTSSCANNER_H_

#include "UserSettings.h"

namespace Services::PortsScanner::Settings
{
    static QStringList GetUserDataPaths()
    {
        return  QStringList( UserSettings->Get_UserDataPathAbs());
    }
}

#endif // _CFG_PORTSSCANNER_H_
