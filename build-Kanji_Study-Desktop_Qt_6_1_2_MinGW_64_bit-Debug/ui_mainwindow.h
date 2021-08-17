/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *nextButton;
    QFrame *frame;
    QLabel *kanjiLabel;
    QLabel *idLabel;
    QLabel *lvlLabel;
    QLabel *readingLabel;
    QLabel *translationLabel;
    QPushButton *pushButton;
    QPushButton *answerButton;
    QFrame *line;
    QCheckBox *includeKanjiCheckBox;
    QCheckBox *includeVocabularyCheckBox;
    QCheckBox *showLevelCheckBox;
    QPushButton *showDetailsButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1063, 726);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(660, 520, 161, 61));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(130, 30, 791, 461));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        kanjiLabel = new QLabel(frame);
        kanjiLabel->setObjectName(QString::fromUtf8("kanjiLabel"));
        kanjiLabel->setGeometry(QRect(120, 60, 531, 121));
        QFont font;
        font.setPointSize(72);
        kanjiLabel->setFont(font);
        kanjiLabel->setAlignment(Qt::AlignCenter);
        idLabel = new QLabel(frame);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        idLabel->setGeometry(QRect(310, 10, 141, 71));
        QFont font1;
        font1.setPointSize(11);
        idLabel->setFont(font1);
        idLabel->setAlignment(Qt::AlignCenter);
        lvlLabel = new QLabel(frame);
        lvlLabel->setObjectName(QString::fromUtf8("lvlLabel"));
        lvlLabel->setGeometry(QRect(310, 190, 141, 71));
        QFont font2;
        font2.setPointSize(12);
        lvlLabel->setFont(font2);
        lvlLabel->setAlignment(Qt::AlignCenter);
        readingLabel = new QLabel(frame);
        readingLabel->setObjectName(QString::fromUtf8("readingLabel"));
        readingLabel->setGeometry(QRect(10, 240, 741, 91));
        QFont font3;
        font3.setPointSize(28);
        readingLabel->setFont(font3);
        readingLabel->setAlignment(Qt::AlignCenter);
        translationLabel = new QLabel(frame);
        translationLabel->setObjectName(QString::fromUtf8("translationLabel"));
        translationLabel->setGeometry(QRect(20, 340, 721, 91));
        QFont font4;
        font4.setPointSize(24);
        translationLabel->setFont(font4);
        translationLabel->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 520, 161, 61));
        answerButton = new QPushButton(centralwidget);
        answerButton->setObjectName(QString::fromUtf8("answerButton"));
        answerButton->setGeometry(QRect(390, 520, 161, 61));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(130, 500, 791, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        includeKanjiCheckBox = new QCheckBox(centralwidget);
        includeKanjiCheckBox->setObjectName(QString::fromUtf8("includeKanjiCheckBox"));
        includeKanjiCheckBox->setGeometry(QRect(10, 220, 91, 17));
        includeKanjiCheckBox->setChecked(true);
        includeVocabularyCheckBox = new QCheckBox(centralwidget);
        includeVocabularyCheckBox->setObjectName(QString::fromUtf8("includeVocabularyCheckBox"));
        includeVocabularyCheckBox->setGeometry(QRect(10, 240, 121, 61));
        includeVocabularyCheckBox->setChecked(false);
        showLevelCheckBox = new QCheckBox(centralwidget);
        showLevelCheckBox->setObjectName(QString::fromUtf8("showLevelCheckBox"));
        showLevelCheckBox->setGeometry(QRect(10, 350, 121, 61));
        showLevelCheckBox->setChecked(true);
        showDetailsButton = new QPushButton(centralwidget);
        showDetailsButton->setObjectName(QString::fromUtf8("showDetailsButton"));
        showDetailsButton->setGeometry(QRect(660, 600, 161, 41));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1063, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Suivant >", nullptr));
        kanjiLabel->setText(QCoreApplication::translate("MainWindow", "Kanji", nullptr));
        idLabel->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lvlLabel->setText(QCoreApplication::translate("MainWindow", "LVL", nullptr));
        readingLabel->setText(QCoreApplication::translate("MainWindow", "Reading", nullptr));
        translationLabel->setText(QCoreApplication::translate("MainWindow", "Translation", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Manage Data", nullptr));
        answerButton->setText(QCoreApplication::translate("MainWindow", "Reveal Answers", nullptr));
        includeKanjiCheckBox->setText(QCoreApplication::translate("MainWindow", "Include Kanji", nullptr));
        includeVocabularyCheckBox->setText(QCoreApplication::translate("MainWindow", "Include Vocabulary", nullptr));
        showLevelCheckBox->setText(QCoreApplication::translate("MainWindow", "Show Level ?", nullptr));
        showDetailsButton->setText(QCoreApplication::translate("MainWindow", "Show Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
