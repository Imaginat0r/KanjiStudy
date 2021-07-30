QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dataManager.cpp \
    main.cpp \
    mainwindow.cpp \
    C:/DataFrame/src/Vectors/HeteroVector.cc


HEADERS += \
    dataManager.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += "C:/NumCpp/include" \
"C:\Users\brahm\Downloads\boost_1_77_0_b1\boost_1_77_0" \
"C:\DataFrame\include"

DISTFILES += \
    Kanji.npy \
    data/Kanji.csv \
    data/Kanji.npy \
    data/Vocabulary.csv
