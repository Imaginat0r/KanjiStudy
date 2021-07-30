#include "mainwindow.h"
#include "dataManager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    dataManager dm("Kanji.npy");
    dm.openExcelFile();

    MainWindow w;
    w.show();
    return a.exec();
}
