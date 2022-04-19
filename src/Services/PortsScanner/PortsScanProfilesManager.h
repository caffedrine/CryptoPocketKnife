#ifndef _PORTSSCANPROFILESMANAGER_H_
#define _PORTSSCANPROFILESMANAGER_H_

#include <QObject>
#include "Singleton.h"

#include "PortsScanBuiltInProfiles.h"

namespace Services::PortsScanner
{

class PortsScanProfilesManager: protected QObject, public Singleton<PortsScanProfilesManager>
{
public:
    QList<PortsScanProfileType> GetAll();
    PortsScanProfileType GetByName(QString profile_name);

protected:

private:

};

}

#endif // _PORTSSCANPROFILESMANAGER_H_