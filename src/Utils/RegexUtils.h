/*  
 *  File      : RegexUtils.h
 *  Created on: 2022-05-02
 *      Author: uib74520
 */

#ifndef _REGEXUTILS_H_
#define _REGEXUTILS_H_

#include <QString>
#include <QStringList>

namespace utils::regex
{
    QStringList GetAllMatches(QString regexPattern, QString str);
}

#endif // _REGEXUTILS_H_