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
    using MyDataFrame = hmdf::StdDataFrame<unsigned long>;

    MyDataFrame df;

    //Lecture du fichier csv
    std::future<bool> fut = df.read_async("test.csv");
};
