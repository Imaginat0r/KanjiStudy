#include "dataManager.h"

dataManager::dataManager(QString path, MainWindow &ui)
:
        filepath(path),
        ui(&ui),
        ID(0)
        {
            std::cout << "Constructing data manager..." << std::endl;
        };

void dataManager::openExcelFile()
{


};
