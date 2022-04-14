#ifndef _NMAPXMLPARSER_H_
#define _NMAPXMLPARSER_H_

#include <QDomDocument>

class nMapXmlParser
{
public:
    nMapXmlParser();
    nMapXmlParser(const QString &nMap_XML);
    ~nMapXmlParser();
    bool ParseXML(const QString &nMap_XML);
    bool IsValidXML();
    QString GetParsingErrorDesc();
    QString GetInputXML();

    QString GetNmapParam_TargetAddress();
    QString GetNmapParam_TargetRDNS();
    QString GetNmapParam_TargetState();


protected:

private:
    QString ParsingErrorDesc;
    QDomDocument xml;

};

#endif // _NMAPXMLPARSER_H_