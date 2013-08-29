#-------------------------------------------------
#
# Project created by QtCreator 2011-12-16T16:05:26
#
#-------------------------------------------------

QT       += core gui

TARGET = qtar8200
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp \
    qsmeter.cpp \
    qrig.cpp \
    qfrequencydatabase.cpp \
    qfrequencycategorytree.cpp \
    qtools.cpp

HEADERS  += mainwindow.h \
    qsmeter.h \
    qrig.h \
    qfrequencydatabase.h \
    qfrequencycategorytree.h \
    tools.h \
    qtools.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += \
    qtar8200.qrc

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += hamlib
unix: LIBS += -lhamlib-aor

unix: PKGCONFIG += QtSql
unix: PKGCONFIG += QtMultimedia

unix: PKGCONFIG += openal
