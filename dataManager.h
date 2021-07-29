#include <xlnt/xlnt.hpp>

class dataManager
{

    private:
        int ID;
        std::string filepath;

    public :
        /*Constructor*/
        dataManager(std::string path)
            :
        filepath(path),
        ID(0)
        {
            std::cout << "Constructing data manager..." << std::endl;
        };


};
