/********************************************************************************
** Form generated from reading UI file 'detailswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILSWINDOW_H
#define UI_DETAILSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DetailsWindow
{
public:
    QPushButton *returnButton;
    QFrame *frame;

    void setupUi(QDialog *DetailsWindow)
    {
        if (DetailsWindow->objectName().isEmpty())
            DetailsWindow->setObjectName(QString::fromUtf8("DetailsWindow"));
        DetailsWindow->resize(1229, 669);
        returnButton = new QPushButton(DetailsWindow);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(520, 620, 201, 41));
        frame = new QFrame(DetailsWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 10, 1191, 581));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(DetailsWindow);

        QMetaObject::connectSlotsByName(DetailsWindow);
    } // setupUi

    void retranslateUi(QDialog *DetailsWindow)
    {
        DetailsWindow->setWindowTitle(QCoreApplication::translate("DetailsWindow", "Dialog", nullptr));
        returnButton->setText(QCoreApplication::translate("DetailsWindow", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailsWindow: public Ui_DetailsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILSWINDOW_H
