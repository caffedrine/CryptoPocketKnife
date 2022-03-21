#ifndef WEBSCRAPER_H
#define WEBSCRAPER_H

#include <QObject>

#include "AdvancedTableWidget.h"
#include "Singleton.h"

class WebScraper
{
    public:
        bool Start(AdvancedTableWidget *recordsTable = nullptr);

};

#endif // WEBSCRAPER_H
