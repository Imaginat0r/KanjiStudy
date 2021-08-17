#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QTableWidgetItem>


#include "boost/regex.hpp"
#include "helpers.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent,QString kanjiPath, QString vocabularyPath);
    ~MainWindow();

    void loadData();
    void updateMode();
    void addKanjiEntry(QStringList Entry);
    void removeKanjiSelection(QList<QTableWidgetItem *> selections);
    void saveKanji();

    void addVocabularyEntry(QStringList Entry);
    void removeVocabularySelection(QList<QTableWidgetItem *> selections);
    void saveVocabulary();

    void generateIDs();
    std::vector<int> findKanjis(QStringList KanjiToFind);
    std::vector<bool> matchInVector(std::vector<QString> Vec, QString ElementToMatch);
    std::vector<int> searchKanjiEntry(QStringList Entry);
    std::vector<int> searchVocabularyEntry(QStringList Entry);

    std::vector<QString> getKanji(std::vector<int> idx = {});
    std::vector<QString> getKanji_lvl(std::vector<int> idx = {});
    std::vector<QString> getKanji_Translation(std::vector<int> idx = {});
    std::vector<QString> getKanji_Reading(std::vector<int> idx = {});

    std::vector<QString> getVocabulary(std::vector<int> idx = {});
    std::vector<QString> getVocabulary_lvl(std::vector<int> idx = {});
    std::vector<QString> getVocabulary_Translation(std::vector<int> idx = {});
    std::vector<QString> getVocabulary_Reading(std::vector<int> idx = {});
    

private slots:

    void on_includeKanjiCheckBox_clicked();
    void on_includeVocabularyCheckBox_clicked();
    void on_nextButton_clicked();
    void on_answerButton_clicked();

    void on_showLevelCheckBox_clicked();

    void on_pushButton_clicked();

    void on_showDetailsButton_clicked();

private:
    Ui::MainWindow *ui;
    int current_ID;

    QString KanjiFilePath;
    QString VocabularyFilePath;

    bool KanjiMode;
    bool VocabularyMode;

    int randomListSelector;
    int randomWordSelector;

    std::vector<QString> Kanji;
    std::vector<QString> Kanji_LVL;
    std::vector<QString> Kanji_Reading;
    std::vector<QString> Kanji_Translation;
    std::vector<QString> Kanji_ID;

    std::vector<QString> Vocabulary;
    std::vector<QString> Vocabulary_LVL;
    std::vector<QString> Vocabulary_Reading;
    std::vector<QString> Vocabulary_Translation;



};
#endif // MAINWINDOW_H
