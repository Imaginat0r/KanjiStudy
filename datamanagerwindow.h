#ifndef DATAMANAGERWINDOW_H
#define DATAMANAGERWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include "boost/regex.hpp"

namespace Ui {
class dataManagerWindow;
}

class dataManagerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit dataManagerWindow(QWidget *parent = nullptr, MainWindow *parentWindow = nullptr,
                               QString KanjiPath = "", QString VocabularyPath="");
    ~dataManagerWindow();

   void loadData();
   void closeEvent(QCloseEvent *event) override;
   void loadKanji(std::vector<int> idx = {});
   void loadVocabulary(std::vector<int> idx = {});

private slots:
    void on_returnButton_clicked();

    void on_removeSelectionKanjiButton_clicked();

    void on_addKanjiButton_clicked();

    void on_addVocabularyButton_clicked();

    void on_removeSelectionVocabularyButton_clicked();

    void on_searchKanjiButton_clicked();

    void on_searchVocabularyButton_clicked();

private:
    Ui::dataManagerWindow *ui;
    MainWindow *parentWindow;
    QString KanjiFilepath;
    QString VocabularyFilepath;

};

#endif // DATAMANAGERWINDOW_H
