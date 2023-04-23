TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        engine.cpp \
        main.cpp \
        robots.cpp \
        worm.cpp \
        ../gtest/googletest/src/gtest-all.cc
INCLUDEPATH += ../gtest  \
                        ../gtest/googletest \
                        ../gtest/googletest/include \
                        ../gtest/googletest/include/gtest
HEADERS += \
    engine.h \
    robots.h \
    worm.h
#LIBS += -lnurcses
