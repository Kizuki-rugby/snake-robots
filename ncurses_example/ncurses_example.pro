TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

win32:INCLUDEPATH += C:\QT\Tools\mingw1120_64\opt\include\ncursesw \
                     C:\QT\Tools\mingw1120_64\opt\include

win32:LIBS += C:\QT\Tools\mingw1120_64\opt\lib\libncurses.a

unix:LIBS += -lncurses

SOURCES += main.cpp \
    value.cpp

HEADERS += \
    value.h
