#ifndef WEBSCRAPER_H
#define WEBSCRAPER_H

#include <QObject>

#include "AdvancedTableWidget.h"

class WebScraper
{
    public:
        bool Start(AdvancedTableWidget *recordsTable = nullptr);

};

#endif // WEBSCRAPER_H
