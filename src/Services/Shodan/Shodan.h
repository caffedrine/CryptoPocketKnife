#ifndef _SHODAN_H_
#define _SHODAN_H_

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include "HttpWebRequest.h"

class Shodan: public QObject
{
Q_OBJECT
public:
    const QString BASE_PATH = "https://api.shodan.io";

    explicit Shodan(QString apiKey);
    ~Shodan();

    QString GetAccountInfo()
    {
        QJsonDocument response = this->CallApi(QNetworkAccessManager::GetOperation, "/account/profile?key=" + this->ApiKey);
        if( response.object().empty() )
            return "error while connecting to shodan";

        if( response.object().contains("error"))
            return "shodan error:" + response.object().value("error").toString();

        return "Credits available: " + response.object().value("credits").toString();
    }
    QString GetSearchFilters()
    {
        QJsonDocument response = this->CallApi(QNetworkAccessManager::GetOperation, "/shodan/host/search/filters?key=" + this->ApiKey);

        if( response.isArray() )
        {
            QString output = "";
            for( QJsonValue v: response.array() )
            {
                output += v.toString() + "\n";
            }
            return output;
        }

        if( response.isEmpty())
            return "error while connecting to shodan: empty json";

        if( response.object().contains("error"))
            return "shodan error:" + response.object().value("error").toString();

        return QString(response.toJson());
    }
    QString GetCountByQuery(QString query)
    {
        QJsonDocument response = this->CallApi(QNetworkAccessManager::GetOperation, "/shodan/host/count?key=" + this->ApiKey + "&query=" + query);

        if( response.object().isEmpty() )
            return "-1";

        if( response.object().contains("error"))
            return "-1";

        QJsonObject object = response.object();

        return object.value("total").toString();
    }

protected:
    QJsonDocument CallApi(QNetworkAccessManager::Operation method, const QString& endpoint);

private:
    HttpWebRequest *http = nullptr;
    QString ApiKey = "";

};

#endif // _SHODAN_H_