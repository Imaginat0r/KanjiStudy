#include "dataManager.h"

dataManager::dataManager(std::string path)
:
        filepath(path),
        ID(0)
        {
            std::cout << "Constructing data manager..." << std::endl;
        };

void dataManager::openExcelFile()
{
   //nc::load<std::string>(filepath);
};
