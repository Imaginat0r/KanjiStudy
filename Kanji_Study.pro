QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    datamanagerwindow.cpp \
    detailswindow.cpp \
    helpers.cpp \
    main.cpp \
    mainwindow.cpp


HEADERS += \
    datamanagerwindow.h \
    detailswindow.h \
    helpers.h \
    mainwindow.h

FORMS += \
    datamanagerwindow.ui \
    detailswindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += "C:\boost_1_77_0_b1\boost_1_77_0"


DISTFILES += \
    Kanji.npy \
    data/Kanji.csv \
    data/Kanji.npy \
    data/Vocabulary.csv \
    data/test.csv
