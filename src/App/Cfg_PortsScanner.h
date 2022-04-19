#ifndef _CFG_PORTSSCANNER_H_
#define _CFG_PORTSSCANNER_H_

#include "UserSettings.h"

namespace Services::PortsScanner
{
    const QStringList USER_DATA_LOCATIONS_ABS = UserSettings::instance().GetUserDataLocationsAbs();
}

#endif // _CFG_PORTSSCANNER_H_
