#ifndef _NMAPXMLPARSER_H_
#define _NMAPXMLPARSER_H_

#include <QDomDocument>
#include <QList>

class nMapPortState
{
public:
    quint16 PortNumber;
    QString Protocol;
    QString State;
};

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
    QDomDocument const *GetInputDomDocument();

    QString GetNmapParam_TargetAddress();
    QString GetNmapParam_TargetRDNS();
    QString GetNmapParam_TargetState();
    QList<nMapPortState> GetNmapParam_OpenPorts();

protected:

private:
    QString ParsingErrorDesc;
    QDomDocument xml;

};

#endif // _NMAPXMLPARSER_H_