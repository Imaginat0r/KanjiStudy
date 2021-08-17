#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datamanagerwindow.h"
#include "detailswindow.h"

MainWindow::MainWindow(QWidget *parent,QString kanjiPath, QString vocabularyPath)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      current_ID(0),
      KanjiMode(true),
      VocabularyMode(false),
      KanjiFilePath(kanjiPath),
      VocabularyFilePath(vocabularyPath)
{
    ui->setupUi(this);

    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);

    QPixmap bkgnd("C:/Users/brahm/PROJETS_TRAVAIL_PDF/PROJETS/C++/Kanji_Quiz/Kanji_Study/bkg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loadData()
{

    std::string data;
    QStringList wordList;
    boost::regex re("(^[N1|N2|N3|N4|N5])");
    boost::sregex_token_iterator j;


    //Load Kanji
    QFile mFile(KanjiFilePath);
    if (!mFile.open(QFile::Text | QFile::ReadOnly))
    {
        return;
    }

    QTextStream inFile(&mFile);

    //Reading Kanji File
    data = inFile.readAll().toUtf8().constData();
    boost::sregex_token_iterator i(data.begin(), data.end(), re, -1);

    *i++;
    *i++;
    while(i != j)
    {
            wordList = QString::fromStdString(*i).split(";");
            if (wordList.isEmpty())
            {
                continue;
            }

            Kanji_LVL.push_back(wordList[0]);
            Kanji.push_back(wordList[1]);
            Kanji_Translation.push_back(wordList[2]);
            Kanji_Reading.push_back(wordList[3]);
            *i++;
    }

    mFile.flush();
    mFile.close();

    //Load Vocabulary
    QFile mFile2(VocabularyFilePath);
    if (!mFile2.open(QFile::Text | QFile::ReadOnly))
    {
        return;
    }

    QTextStream inFile2(&mFile2);

    //Reading Kanji File
    data = inFile2.readAll().toUtf8().constData();
    boost::sregex_token_iterator i2(data.begin(), data.end(), re, -1);

    *i2++;
    *i2++;
    while(i2 != j)
    {
            wordList = QString::fromStdString(*i2).split(";");
            if (wordList.isEmpty())
            {
                continue;
            }

            Vocabulary_LVL.push_back(wordList[0]);
            Vocabulary.push_back(wordList[1]);
            Vocabulary_Translation.push_back(wordList[2]);
            Vocabulary_Reading.push_back(wordList[3]);
            *i2++;
    }

    mFile2.flush();
    mFile2.close();
}


void MainWindow::updateMode()
{
    qDebug() << "Changing Mode";
    KanjiMode = ui->includeKanjiCheckBox->isChecked();
    VocabularyMode = ui->includeVocabularyCheckBox->isChecked();

    // Cas où rien n'est coché
    if (!KanjiMode && !VocabularyMode)
    {
        ui->includeKanjiCheckBox->setCheckState(Qt::CheckState::Checked);
        KanjiMode = true;
    }

}


void MainWindow::on_includeKanjiCheckBox_clicked()
{
    updateMode();
}


void MainWindow::on_includeVocabularyCheckBox_clicked()
{
    updateMode();
}


void MainWindow::on_nextButton_clicked()
{

    if (KanjiMode && !VocabularyMode)
    {
        randomListSelector = 0;
    }
    else if (!KanjiMode && VocabularyMode)
    {
        randomListSelector = 1;
    }
    else
    {
        randomListSelector = rand()%2;
    }

    //Vocabulary OR Kanji
    if (randomListSelector==0)
    {
       randomWordSelector = rand() % Kanji.size();
       ui->kanjiLabel->setText(Kanji[randomWordSelector]);
       ui->kanjiLabel->setWordWrap(true);
       ui->idLabel->setText(QString::number(randomWordSelector));


       if (ui->showLevelCheckBox->isChecked())
            ui->lvlLabel->setText(Kanji_LVL[randomWordSelector]);

       ui->translationLabel->setText("");
       ui->readingLabel->setText("");
    }
    else
    {
        randomWordSelector = rand() % Vocabulary.size();

        if (Vocabulary[randomWordSelector].isEmpty())
        {
             ui->kanjiLabel->setText(Vocabulary_Reading[randomWordSelector]);             
        }
        else
        {
            ui->kanjiLabel->setText(Vocabulary[randomWordSelector]);

        }

        ui->kanjiLabel->setWordWrap(true);

        ui->idLabel->setText(QString::number(randomWordSelector));

        if (ui->showLevelCheckBox->isChecked())
             ui->lvlLabel->setText(Vocabulary_LVL[randomWordSelector]);

        ui->translationLabel->setText("");
        ui->readingLabel->setText("");
    }

}


void MainWindow::on_answerButton_clicked()
{

    if (randomListSelector==0)
    {
      ui->translationLabel->setText(Kanji_Translation[randomWordSelector]);
      ui->readingLabel->setText(Kanji_Reading[randomWordSelector]);
    }
    else
    {
        ui->translationLabel->setText(Vocabulary_Translation[randomWordSelector]);
        ui->readingLabel->setText(Vocabulary_Reading[randomWordSelector]);
    }

    ui->translationLabel->setWordWrap(true);
    ui->readingLabel->setWordWrap(true);

}


void MainWindow::on_showLevelCheckBox_clicked()
{
    if (!(ui->showLevelCheckBox->isChecked()))
        ui->lvlLabel->setText("");
    else
    {
        if (randomListSelector)
            ui->lvlLabel->setText(Kanji_LVL[randomWordSelector]);
        else
            ui->lvlLabel->setText(Vocabulary_LVL[randomWordSelector]);
    }

}


void MainWindow::on_pushButton_clicked()
{
    //Ouvrir le data Manager
    dataManagerWindow *dmw = new dataManagerWindow(nullptr, this, KanjiFilePath, VocabularyFilePath);
    dmw->show();

    this->hide();

}

void MainWindow::removeKanjiSelection(QList<QTableWidgetItem *> selections)
{
    int idx;
    //Remove from vector
    for (int i = selections.size()-1; i == 0;i--)
    {
        idx = selections[i]->row();

        Kanji.erase(Kanji.begin() + idx);
        Kanji_LVL.erase(Kanji_LVL.begin() + idx);
        Kanji_Reading.erase(Kanji_Reading.begin() + idx);
        Kanji_Translation.erase(Kanji_Translation.begin() + idx);

    }




}
void MainWindow::addKanjiEntry(QStringList Entry)
{

    Kanji_LVL.push_back(Entry[0]);
    Kanji.push_back(Entry[1]);
    Kanji_Translation.push_back(Entry[2]);
    Kanji_Reading.push_back(Entry[3]);

}

void MainWindow::saveKanji()
{
    //Save vectors in csv format
    QFile file("C:/Users/brahm/PROJETS_TRAVAIL_PDF/PROJETS/C++/Kanji_Quiz/Kanji_Study/data/Kanji.csv");
    if (file.open(QFile::WriteOnly|QFile::Truncate))
    {
        file.resize(0);
        qDebug() << "Writing File...";
        QTextStream stream(&file);
        stream << "Niveau" << ";" << "Kanji" << ";" << "Signification" << ";" << "Lecture ON  /  Lecture KUN" << "\n"; // this writes first line with two columns

        for (int i = 0; i < Kanji.size(); i++)
        {
            stream << "N" << Kanji_LVL[i] << ";" << Kanji[i] << ";" << Kanji_Translation[i] << ";" << Kanji_Reading[i];
        }

        file.flush();
        file.close();
    }

}



void MainWindow::addVocabularyEntry(QStringList Entry)
{

    Vocabulary_LVL.push_back(Entry[0]);
    Vocabulary.push_back(Entry[1]);
    Vocabulary_Translation.push_back(Entry[2]);
    Vocabulary_Reading.push_back(Entry[3]);

}

void MainWindow::removeVocabularySelection(QList<QTableWidgetItem *> selections)
{
    int idx;
    //Remove from vector
    for (int i = selections.size()-1; i == 0;i--)
    {
        idx = selections[i]->row();

        Vocabulary.erase(Vocabulary.begin() + idx);
        Vocabulary_LVL.erase(Vocabulary_LVL.begin() + idx);
        Vocabulary_Reading.erase(Vocabulary_Reading.begin() + idx);
        Vocabulary_Translation.erase(Vocabulary_Translation.begin() + idx);

    }

}

void MainWindow::saveVocabulary()
{
    //Save vectors in csv format
    QFile file("C:/Users/brahm/PROJETS_TRAVAIL_PDF/PROJETS/C++/Kanji_Quiz/Kanji_Study/data/Vocabulary.csv");

    if (file.open(QFile::WriteOnly|QFile::Truncate))
    {
        file.resize(0);
        qDebug() << "Writing File...";
        QTextStream stream(&file);
        stream << "Niveau" << ";" << "Vocabulaire" << ";" << "Signification" << ";" << "Lecture" << "\n"; // this writes first line with two columns

        for (int i = 0; i < Vocabulary.size(); i++)
        {
            stream << "N" << Vocabulary_LVL[i] << ";" << Vocabulary[i] << ";" << Vocabulary_Translation[i] << ";" << Vocabulary_Reading[i];
        }

        file.flush();
        file.close();
    }
}

void MainWindow::generateIDs()
{
    std::vector<std::string> IDs;

    for(int i = 0 ; i < Kanji.size() ; i++)
    {
        IDs.push_back(string_Hashing((Kanji[i]+Kanji_Translation[i]).toStdString()));
    }

    QFile file("C:/Users/brahm/PROJETS_TRAVAIL_PDF/PROJETS/C++/Kanji_Quiz/Kanji_Study/IDs.txt");
    if (file.open(QFile::WriteOnly|QFile::Truncate))
    {
        qDebug() << "Writing File...";
        QTextStream stream(&file);
        stream << "ID" << "\n"; // this writes first line with two columns

        for (int i = 0; i < Kanji.size(); i++)
        {
            stream << QString::fromStdString(IDs[i]) << "\n";
        }

        file.flush();
        file.close();
    }


}



std::vector<int> MainWindow::findKanjis(QStringList KanjiToFind)
{
    std::vector<int> indexes;
    int result;

    for (int i = 0; i < KanjiToFind.size(); i++)
    {

        result = findInVector(Kanji, KanjiToFind[i]);
        indexes.push_back(result);
    }

    return indexes;
}


std::vector<bool> MainWindow::matchInVector(std::vector<QString> Vec, QString ElementToMatch)
{
    std::vector<bool> res;

    if (ElementToMatch.isEmpty())
    {
        for (int k = 0; k < Vec.size(); k++)
        {
            res.push_back(true);
        }
        return res;
    }


    for (int k = 0; k < Vec.size(); k++)
    {
        res.push_back(Vec[k].contains(ElementToMatch));
    }

    return res;

}



void MainWindow::on_showDetailsButton_clicked()
{

    std::vector<int> indexes;
    std::vector<QStringList> Kanjis;


    if (randomListSelector==0)
    {
        QStringList KanjiDetail;
        KanjiDetail.append(Kanji_LVL[randomWordSelector]);
        KanjiDetail.append(Kanji[randomWordSelector]);
        KanjiDetail.append(Kanji_Reading[randomWordSelector]);
        KanjiDetail.append(Kanji_Translation[randomWordSelector]);
        Kanjis.push_back(KanjiDetail);

    }
    else
    {
        QStringList KanjiToFind;

        for (int k = 0; k < Vocabulary[randomWordSelector].size(); k++)
            KanjiToFind.append(Vocabulary[randomWordSelector][k]);

        indexes = findKanjis(KanjiToFind);

        for (int i =0; i < indexes.size(); i++)
        {
            QStringList KanjiDetail;

            //Si le kanji a été trouvé
            if (indexes[i] != -1)
            {
                KanjiDetail.append(Kanji_LVL[indexes[i]]);
                KanjiDetail.append(Kanji[indexes[i]]);
                KanjiDetail.append(Kanji_Reading[indexes[i]]);
                KanjiDetail.append(Kanji_Translation[indexes[i]]);
                Kanjis.push_back(KanjiDetail);
            }
        }


    }

   DetailsWindow *dw = new DetailsWindow(this);
   dw->DisplayKanjis(Kanjis);
   dw->show();

   this->hide();

}

std::vector<QString> MainWindow::getKanji(std::vector<int> idx)
{
    if (idx.empty())
        return Kanji;
    else
    {
        std::vector<QString> Res;
        for (int i = 0; i < idx.size(); ++i)
           Res.push_back(Kanji[idx[i]]);

        return Res;
    }
}

std::vector<QString> MainWindow::getKanji_lvl(std::vector<int> idx)
{
    if (idx.empty())
        return Kanji_LVL;
    else
    {
        std::vector<QString> Res;
        for (int i = 0; i < idx.size(); ++i)
           Res.push_back(Kanji_LVL[idx[i]]);

        return Res;
    }

}

std::vector<QString> MainWindow::getKanji_Translation(std::vector<int> idx)
{
    if (idx.empty())
        return Kanji_Translation;
    else
    {
        std::vector<QString> Res;
        for (int i = 0; i < idx.size(); ++i)
           Res.push_back(Kanji_Translation[idx[i]]);

        return Res;
    }
}

std::vector<QString> MainWindow::getKanji_Reading(std::vector<int> idx)
{
    if (idx.empty())
        return Kanji_Reading;
    else
    {
        std::vector<QString> Res;
        for (int i = 0; i < idx.size(); ++i)
           Res.push_back(Kanji_Reading[idx[i]]);

        return Res;
    }

}


std::vector<QString> MainWindow::getVocabulary(std::vector<int> idx)
{
    if (idx.empty())
        return Vocabulary;
    else
    {
        std::vector<QString> Res;
        for (int i = 0; i < idx.size(); ++i)
           Res.push_back(Vocabulary[idx[i]]);

        return Res;
    }
}

std::vector<QString> MainWindow::getVocabulary_lvl(std::vector<int> idx)
{
    if (idx.empty())
        return Vocabulary_LVL;
    else
    {
        std::vector<QString> Res;
        for (int i = 0; i < idx.size(); ++i)
           Res.push_back(Vocabulary_LVL[idx[i]]);

        return Res;
    }

}

std::vector<QString> MainWindow::getVocabulary_Translation(std::vector<int> idx)
{
    if (idx.empty())
        return Vocabulary_Translation;
    else
    {
        std::vector<QString> Res;
        for (int i = 0; i < idx.size(); ++i)
           Res.push_back(Vocabulary_Translation[idx[i]]);

        return Res;
    }
}

std::vector<QString> MainWindow::getVocabulary_Reading(std::vector<int> idx)
{
    if (idx.empty())
        return Vocabulary_Reading;
    else
    {
        std::vector<QString> Res;
        for (int i = 0; i < idx.size(); ++i)
           Res.push_back(Vocabulary_Reading[idx[i]]);

        return Res;
    }

}



std::vector<int> MainWindow::searchKanjiEntry(QStringList Entry)
{
    std::vector<bool> KanjiResult, KanjiLvlResult, KanjiReadingResult,KanjiTranslationResult;
    std::vector<int> idx;

    KanjiLvlResult = matchInVector(Kanji_LVL,Entry[0]);
    KanjiResult = matchInVector(Kanji,Entry[1]);
    KanjiTranslationResult = matchInVector(Kanji_Translation,Entry[2]);
    KanjiReadingResult = matchInVector(Kanji_Reading,Entry[3]);

    for (int i =0; i < KanjiResult.size(); i++)
    {
        if (KanjiLvlResult[i] && KanjiResult[i] && KanjiTranslationResult[i] && KanjiReadingResult[i])
            idx.push_back(i);
    }

    return idx;
}

std::vector<int> MainWindow::searchVocabularyEntry(QStringList Entry)
{
    std::vector<bool> VocabularyResult, VocabularyLvlResult, VocabularyReadingResult,VocabularyTranslationResult;
    std::vector<int> idx;

    VocabularyLvlResult = matchInVector(Vocabulary_LVL,Entry[0]);
    VocabularyResult = matchInVector(Vocabulary,Entry[1]);
    VocabularyTranslationResult = matchInVector(Vocabulary_Translation,Entry[2]);
    VocabularyReadingResult = matchInVector(Vocabulary_Reading,Entry[3]);

    for (int i =0; i < VocabularyResult.size(); i++)
    {
        if (VocabularyLvlResult[i] && VocabularyResult[i] && VocabularyTranslationResult[i] && VocabularyReadingResult[i])
            idx.push_back(i);
    }

    return idx;


}
