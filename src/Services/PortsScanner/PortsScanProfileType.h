#ifndef _PORTSSCANPROFILE_H_
#define _PORTSSCANPROFILE_H_

#include <QString>
#include <QList>
#include <QMap>

#include "PortScanTargetType.h"

namespace Services::PortsScanner
{

class PortsScanProfileType
{
public:
    PortsScanProfileType() = default;
    ~PortsScanProfileType()= default;

    QString ProfileName;
    QString DeviceCategoryIfProfileMatch = "ICS";
    bool BuiltInProfile;

    QList<PortsScanTargetType> Targets;

protected:

private:

};

}

#endif // _PORTSSCANPROFILE_H_