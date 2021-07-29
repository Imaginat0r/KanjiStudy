#include <iostream>
#include<string>

#include "NumCpp.hpp"
#include <cstdlib>


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
