TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp


win32:INCLUDEPATH += C:\QT\Tools\mingw1120_64\opt\include          \
                     C:\QT\Tools\mingw1120_64\opt\include\ncursesw

win32:LIBS +=  C:\QT\Tools\mingw1120_64\opt\lib\libformw.a         \
               C:\QT\Tools\mingw1120_64\opt\lib\libncurses.a


unix:LIBS += -lncurses -lform
