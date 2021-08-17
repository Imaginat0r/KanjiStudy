#include "datamanagerwindow.h"
#include "ui_datamanagerwindow.h"
#include "helpers.h"

dataManagerWindow::dataManagerWindow(QWidget *parent, MainWindow *parentWindow,
                                     QString KanjiPath, QString VocabularyPath) :
    QDialog(parent),
    parentWindow(parentWindow),
    KanjiFilepath(KanjiPath),
    VocabularyFilepath(VocabularyPath),
    ui(new Ui::dataManagerWindow)
{
    ui->setupUi(this);

    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);

    QPixmap bkgnd("C:/Users/brahm/PROJETS_TRAVAIL_PDF/PROJETS/C++/Kanji_Quiz/Kanji_Study/bkg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);


    loadData();
}

dataManagerWindow::~dataManagerWindow()
{
    parentWindow->show();
    delete ui;
}

void dataManagerWindow::on_returnButton_clicked()
{
    this->close();
    parentWindow->show();

}


void dataManagerWindow::loadData()
{
    std::string data;
    QStringList wordList;
    boost::regex re("(^[N1|N2|N3|N4|N5])");
    boost::sregex_token_iterator j;


    //Load Kanji
    QFile mFile(KanjiFilepath);
    if (!mFile.open(QFile::Text | QFile::ReadOnly))
    {
        return;
    }

    QTextStream inFile(&mFile);


    QString FirstLine;
    FirstLine = inFile.readLine();
    wordList = FirstLine.split(";");
    ui->KanjiTable->setColumnCount(wordList.size());
    ui->KanjiTable->setHorizontalHeaderLabels(wordList);

    //Reading Kanji File
    data = inFile.readAll().toUtf8().constData();
    boost::sregex_token_iterator i(data.begin(), data.end(), re, -1);
    int ctr = 0;

    *i++;

    while(i != j)
    {
            ctr++;
            ui->KanjiTable->setRowCount(ctr);

            wordList = QString::fromStdString(*i).split(";");
            if (wordList.isEmpty())
            {
                continue;
            }


            for(int k=0 ;k<wordList.size();k++)
            {
                ui->KanjiTable->setItem(ctr-1,k,new QTableWidgetItem(wordList[k]));
            }


            *i++;

    }

    mFile.flush();
    mFile.close();

    //Load Vocabulary
    QFile mFile2(VocabularyFilepath);
    if (!mFile2.open(QFile::Text | QFile::ReadOnly))
    {
        return;
    }

    QTextStream inFile2(&mFile2);


    FirstLine = inFile2.readLine();
    wordList = FirstLine.split(";");
    ui->VocabularyTable->setColumnCount(wordList.size());
    ui->VocabularyTable->setHorizontalHeaderLabels(wordList);

    //Reading Vocabulary File
    data = inFile2.readAll().toUtf8().constData();
    boost::sregex_token_iterator i2(data.begin(), data.end(), re, -1);
    ctr = 0;

    *i2++;
    while(i2 != j)
    {
            ctr++;
            ui->VocabularyTable->setRowCount(ctr);

            wordList = QString::fromStdString(*i2).split(";");
            if (wordList.isEmpty())
            {
                continue;
            }

            for(int k=0 ;k<wordList.size();k++)
            {
                ui->VocabularyTable->setItem(ctr-1,k,new QTableWidgetItem(wordList[k]));
            }


            *i2++;

    }

    mFile2.flush();
    mFile2.close();
}

void dataManagerWindow::closeEvent(QCloseEvent *event)
{
     parentWindow->show();
}


void dataManagerWindow::on_removeSelectionKanjiButton_clicked()
{
    QList<QTableWidgetItem *> selections = ui->KanjiTable->selectedItems();
    parentWindow->removeKanjiSelection(selections);
    parentWindow->saveKanji();

    loadData();

}


void dataManagerWindow::on_addKanjiButton_clicked()
{
    QStringList Entry;
    QString E1{ui->KanjiEntry->toPlainText()},
    E2{ui->KanjiTranslationEntry->toPlainText()},
    E3{ui->KanjiReadingEntry->toPlainText()};

    Entry.append(QString::number(ui->KanjiLvlEntry->value()));

    if (E1.isEmpty() || E2.isEmpty() || E3.isEmpty())
        return;

    Entry.append(E1);
    Entry.append(E2);
    Entry.append(E3);

    parentWindow->addKanjiEntry(Entry);
    parentWindow->saveKanji();

    qDebug() << "Valid Entry";

    loadData();

}


void dataManagerWindow::on_addVocabularyButton_clicked()
{
    QStringList Entry;
    QString E1{ui->VocabularyEntry->toPlainText()},
    E2{ui->VocabularyTranslationEntry->toPlainText()},
    E3{ui->VocabularyReadingEntry->toPlainText()};

    Entry.append(QString::number(ui->VocabularyLvlEntry->value()));

    if (E1.isEmpty() || E2.isEmpty() || E3.isEmpty())
        return;

    Entry.append(E1);
    Entry.append(E2);
    Entry.append(E3);

    parentWindow->addVocabularyEntry(Entry);
    parentWindow->saveVocabulary();

    qDebug() << "Valid Entry";

    loadData();
}




void dataManagerWindow::on_removeSelectionVocabularyButton_clicked()
{
    QList<QTableWidgetItem *> selections = ui->VocabularyTable->selectedItems();
    parentWindow->removeVocabularySelection(selections);
    parentWindow->saveVocabulary();

    loadData();
}

void dataManagerWindow::loadKanji(std::vector<int> idx)
{
    std::vector<QString> Kanji, Kanji_lvl, Kanji_Reading, Kanji_Translation;
    Kanji = parentWindow->getKanji(idx);
    Kanji_lvl = parentWindow->getKanji_lvl(idx);
    Kanji_Reading = parentWindow->getKanji_Reading(idx);
    Kanji_Translation = parentWindow->getKanji_Translation(idx);

    ui->KanjiTable->clearContents();

    for (int k = 0; k < Kanji.size(); k++)
    {

                ui->KanjiTable->setRowCount(k+1);

                ui->KanjiTable->setItem(k,0,new QTableWidgetItem(Kanji_lvl[k]));
                ui->KanjiTable->setItem(k,1,new QTableWidgetItem(Kanji[k]));
                ui->KanjiTable->setItem(k,2,new QTableWidgetItem(Kanji_Translation[k]));
                ui->KanjiTable->setItem(k,3,new QTableWidgetItem(Kanji_Reading[k]));


    }

}

void dataManagerWindow::loadVocabulary(std::vector<int> idx)
{
    std::vector<QString> Vocabulary, Vocabulary_lvl, Vocabulary_Reading, Vocabulary_Translation;
    Vocabulary = parentWindow->getVocabulary(idx);
    Vocabulary_lvl = parentWindow->getVocabulary_lvl(idx);
    Vocabulary_Reading = parentWindow->getVocabulary_Reading(idx);
    Vocabulary_Translation = parentWindow->getVocabulary_Translation(idx);

    ui->VocabularyTable->clearContents();

    for (int k = 0; k < Vocabulary.size(); k++)
    {

                ui->VocabularyTable->setRowCount(k+1);

                ui->VocabularyTable->setItem(k,0,new QTableWidgetItem(Vocabulary_lvl[k]));
                ui->VocabularyTable->setItem(k,1,new QTableWidgetItem(Vocabulary[k]));
                ui->VocabularyTable->setItem(k,2,new QTableWidgetItem(Vocabulary_Translation[k]));
                ui->VocabularyTable->setItem(k,3,new QTableWidgetItem(Vocabulary_Reading[k]));


    }

}



void dataManagerWindow::on_searchKanjiButton_clicked()
{
    QStringList Entry;
    QString E1{ui->KanjiEntry->toPlainText()},
    E2{ui->KanjiTranslationEntry->toPlainText()},
    E3{ui->KanjiReadingEntry->toPlainText()};
    Entry.append(QString::number(ui->KanjiLvlEntry->value()));

    Entry.append(E1);
    Entry.append(E2);
    Entry.append(E3);


    std::vector<int> indexResult;

    indexResult = parentWindow->searchKanjiEntry(Entry);
    loadKanji(indexResult);
}


void dataManagerWindow::on_searchVocabularyButton_clicked()
{
    QStringList Entry;
    QString E1{ui->VocabularyEntry->toPlainText()},
    E2{ui->VocabularyTranslationEntry->toPlainText()},
    E3{ui->VocabularyReadingEntry->toPlainText()};
    Entry.append(QString::number(ui->VocabularyLvlEntry->value()));

    Entry.append(E1);
    Entry.append(E2);
    Entry.append(E3);


    std::vector<int> indexResult;

    indexResult = parentWindow->searchVocabularyEntry(Entry);
    loadVocabulary(indexResult);

}

