/********************************************************************************
** Form generated from reading UI file 'datamanagerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMANAGERWINDOW_H
#define UI_DATAMANAGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_dataManagerWindow
{
public:
    QTableWidget *KanjiTable;
    QTableWidget *VocabularyTable;
    QPushButton *removeSelectionKanjiButton;
    QPushButton *removeSelectionVocabularyButton;
    QPushButton *addKanjiButton;
    QPushButton *addVocabularyButton;
    QPushButton *returnButton;
    QSpinBox *KanjiLvlEntry;
    QPlainTextEdit *KanjiEntry;
    QPlainTextEdit *KanjiReadingEntry;
    QPlainTextEdit *KanjiTranslationEntry;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPlainTextEdit *VocabularyReadingEntry;
    QSpinBox *VocabularyLvlEntry;
    QPlainTextEdit *VocabularyTranslationEntry;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPlainTextEdit *VocabularyEntry;
    QPushButton *searchKanjiButton;
    QPushButton *searchVocabularyButton;

    void setupUi(QDialog *dataManagerWindow)
    {
        if (dataManagerWindow->objectName().isEmpty())
            dataManagerWindow->setObjectName(QString::fromUtf8("dataManagerWindow"));
        dataManagerWindow->resize(1318, 669);
        KanjiTable = new QTableWidget(dataManagerWindow);
        KanjiTable->setObjectName(QString::fromUtf8("KanjiTable"));
        KanjiTable->setGeometry(QRect(20, 100, 601, 331));
        VocabularyTable = new QTableWidget(dataManagerWindow);
        VocabularyTable->setObjectName(QString::fromUtf8("VocabularyTable"));
        VocabularyTable->setGeometry(QRect(650, 100, 631, 331));
        removeSelectionKanjiButton = new QPushButton(dataManagerWindow);
        removeSelectionKanjiButton->setObjectName(QString::fromUtf8("removeSelectionKanjiButton"));
        removeSelectionKanjiButton->setGeometry(QRect(240, 470, 201, 23));
        removeSelectionVocabularyButton = new QPushButton(dataManagerWindow);
        removeSelectionVocabularyButton->setObjectName(QString::fromUtf8("removeSelectionVocabularyButton"));
        removeSelectionVocabularyButton->setGeometry(QRect(870, 470, 201, 23));
        addKanjiButton = new QPushButton(dataManagerWindow);
        addKanjiButton->setObjectName(QString::fromUtf8("addKanjiButton"));
        addKanjiButton->setGeometry(QRect(320, 580, 201, 31));
        addVocabularyButton = new QPushButton(dataManagerWindow);
        addVocabularyButton->setObjectName(QString::fromUtf8("addVocabularyButton"));
        addVocabularyButton->setGeometry(QRect(1000, 580, 201, 31));
        returnButton = new QPushButton(dataManagerWindow);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(560, 610, 171, 41));
        KanjiLvlEntry = new QSpinBox(dataManagerWindow);
        KanjiLvlEntry->setObjectName(QString::fromUtf8("KanjiLvlEntry"));
        KanjiLvlEntry->setGeometry(QRect(30, 510, 61, 31));
        KanjiLvlEntry->setMinimum(1);
        KanjiLvlEntry->setMaximum(5);
        KanjiEntry = new QPlainTextEdit(dataManagerWindow);
        KanjiEntry->setObjectName(QString::fromUtf8("KanjiEntry"));
        KanjiEntry->setGeometry(QRect(120, 510, 104, 31));
        KanjiReadingEntry = new QPlainTextEdit(dataManagerWindow);
        KanjiReadingEntry->setObjectName(QString::fromUtf8("KanjiReadingEntry"));
        KanjiReadingEntry->setGeometry(QRect(250, 510, 171, 31));
        KanjiTranslationEntry = new QPlainTextEdit(dataManagerWindow);
        KanjiTranslationEntry->setObjectName(QString::fromUtf8("KanjiTranslationEntry"));
        KanjiTranslationEntry->setGeometry(QRect(440, 510, 171, 31));
        label = new QLabel(dataManagerWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 550, 47, 13));
        label_2 = new QLabel(dataManagerWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 550, 47, 13));
        label_3 = new QLabel(dataManagerWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 550, 47, 13));
        label_4 = new QLabel(dataManagerWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 550, 61, 16));
        VocabularyReadingEntry = new QPlainTextEdit(dataManagerWindow);
        VocabularyReadingEntry->setObjectName(QString::fromUtf8("VocabularyReadingEntry"));
        VocabularyReadingEntry->setGeometry(QRect(990, 520, 161, 31));
        VocabularyLvlEntry = new QSpinBox(dataManagerWindow);
        VocabularyLvlEntry->setObjectName(QString::fromUtf8("VocabularyLvlEntry"));
        VocabularyLvlEntry->setGeometry(QRect(690, 520, 61, 31));
        VocabularyLvlEntry->setMinimum(1);
        VocabularyLvlEntry->setMaximum(5);
        VocabularyTranslationEntry = new QPlainTextEdit(dataManagerWindow);
        VocabularyTranslationEntry->setObjectName(QString::fromUtf8("VocabularyTranslationEntry"));
        VocabularyTranslationEntry->setGeometry(QRect(1170, 520, 121, 31));
        label_5 = new QLabel(dataManagerWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1050, 560, 47, 13));
        label_6 = new QLabel(dataManagerWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(830, 550, 101, 20));
        label_7 = new QLabel(dataManagerWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1200, 560, 61, 16));
        label_8 = new QLabel(dataManagerWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(710, 560, 47, 16));
        VocabularyEntry = new QPlainTextEdit(dataManagerWindow);
        VocabularyEntry->setObjectName(QString::fromUtf8("VocabularyEntry"));
        VocabularyEntry->setGeometry(QRect(790, 520, 181, 31));
        searchKanjiButton = new QPushButton(dataManagerWindow);
        searchKanjiButton->setObjectName(QString::fromUtf8("searchKanjiButton"));
        searchKanjiButton->setGeometry(QRect(90, 580, 161, 31));
        searchVocabularyButton = new QPushButton(dataManagerWindow);
        searchVocabularyButton->setObjectName(QString::fromUtf8("searchVocabularyButton"));
        searchVocabularyButton->setGeometry(QRect(810, 580, 161, 31));

        retranslateUi(dataManagerWindow);

        QMetaObject::connectSlotsByName(dataManagerWindow);
    } // setupUi

    void retranslateUi(QDialog *dataManagerWindow)
    {
        dataManagerWindow->setWindowTitle(QCoreApplication::translate("dataManagerWindow", "Dialog", nullptr));
        removeSelectionKanjiButton->setText(QCoreApplication::translate("dataManagerWindow", "Remove selection", nullptr));
        removeSelectionVocabularyButton->setText(QCoreApplication::translate("dataManagerWindow", "Remove selection", nullptr));
        addKanjiButton->setText(QCoreApplication::translate("dataManagerWindow", "Ajouter le Kanji", nullptr));
        addVocabularyButton->setText(QCoreApplication::translate("dataManagerWindow", "Ajouter le mot de vocabulaire", nullptr));
        returnButton->setText(QCoreApplication::translate("dataManagerWindow", "Retour", nullptr));
        label->setText(QCoreApplication::translate("dataManagerWindow", "Level", nullptr));
        label_2->setText(QCoreApplication::translate("dataManagerWindow", "Kanji", nullptr));
        label_3->setText(QCoreApplication::translate("dataManagerWindow", "Reading", nullptr));
        label_4->setText(QCoreApplication::translate("dataManagerWindow", "Translation", nullptr));
        label_5->setText(QCoreApplication::translate("dataManagerWindow", "Reading", nullptr));
        label_6->setText(QCoreApplication::translate("dataManagerWindow", "Mot de vocabulaire", nullptr));
        label_7->setText(QCoreApplication::translate("dataManagerWindow", "Translation", nullptr));
        label_8->setText(QCoreApplication::translate("dataManagerWindow", "Level", nullptr));
        searchKanjiButton->setText(QCoreApplication::translate("dataManagerWindow", "Rechercher le Kanji", nullptr));
        searchVocabularyButton->setText(QCoreApplication::translate("dataManagerWindow", "Rechercher le vocabulaire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dataManagerWindow: public Ui_dataManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMANAGERWINDOW_H
