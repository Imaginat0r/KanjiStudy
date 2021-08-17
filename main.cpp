#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(nullptr, "C:\\Users\\brahm\\PROJETS_TRAVAIL_PDF\\PROJETS\\C++\\Kanji_Quiz\\Kanji_Study\\data\\Kanji.csv"
,"C:\\Users\\brahm\\PROJETS_TRAVAIL_PDF\\PROJETS\\C++\\Kanji_Quiz\\Kanji_Study\\data\\Vocabulary.csv");

    w.loadData();


    w.show();
    return a.exec();
}
