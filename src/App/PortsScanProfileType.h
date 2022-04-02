/*  
 *  File      : PortsScanProfile.h
 *  Created on: 2022-04-02
 *      Author: uib74520
 */

#ifndef _PORTSSCANPROFILE_H_
#define _PORTSSCANPROFILE_H_

#include <QString>
#include <QList>
#include <QMap>

#include "PortScanTargetType.h"

class PortsScanProfileType
{
public:
    PortsScanProfileType() = default;
    ~PortsScanProfileType()= default;

    QString ProfileName;
    bool BuiltInProfile;

    QList<PortsScanTargetType> Targets;

protected:

private:

};

#endif // _PORTSSCANPROFILE_H_