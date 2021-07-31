#include <iostream>
#include<string>

#include <mainwindow.h>




class dataManager
{

    private:

        MainWindow *ui;

    public :
        /*Constructor*/
        dataManager(QString path, MainWindow &ui);


        void openExcelFile();


};
