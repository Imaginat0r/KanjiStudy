#include <iostream>
#include<string>

#include <DataFrame/DataFrame.h>
#include <DataFrame/DataFrameFinancialVisitors.h>
#include <DataFrame/DataFrameMLVisitors.h>
#include <DataFrame/DataFrameOperators.h>
#include <DataFrame/DataFrameStatsVisitors.h>
#include <DataFrame/RandGen.h>

#include <cassert>
#include <cmath>
#include <limits>
#include <typeinfo>


class dataManager
{

    private:
        int ID;
        std::string filepath;

    public :
        /*Constructor*/
        dataManager(std::string path);


        void openExcelFile();


};
