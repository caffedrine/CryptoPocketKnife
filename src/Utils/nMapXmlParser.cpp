#include "nMapXmlParser.h"

nMapXmlParser::nMapXmlParser()
{
    this->ParsingErrorDesc = "No input";
}

nMapXmlParser::nMapXmlParser(const QString &nMap_XML)
{
    this->ParseXML(nMap_XML);
}

nMapXmlParser::~nMapXmlParser()
{

}

bool nMapXmlParser::IsValidXML()
{
    return this->ParsingErrorDesc.isEmpty();
}

QString nMapXmlParser::GetParsingErrorDesc()
{
    return this->ParsingErrorDesc;
}

QString nMapXmlParser::GetInputXML()
{
    return this->xml.toString(4);
}

QString nMapXmlParser::GetNmapParam_TargetAddress()
{
    return this->xml.documentElement().elementsByTagName("address").item(0).toElement().attribute("addr");
}

QString nMapXmlParser::GetNmapParam_TargetRDNS()
{
    return this->xml.documentElement().elementsByTagName("hostname").item(0).toElement().attribute("name");
}

QString nMapXmlParser::GetNmapParam_TargetState()
{
    return this->xml.documentElement().elementsByTagName("status").item(0).toElement().attribute("state").toUpper();
}

bool nMapXmlParser::ParseXML(const QString &nMap_XML)
{
    this->ParsingErrorDesc = "";
    this->xml.setContent(nMap_XML, &this->ParsingErrorDesc);
    return this->IsValidXML();
}
