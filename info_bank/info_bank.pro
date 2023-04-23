TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    additionalscreen.cpp \
    createplayer.cpp \
    game.cpp \
    gamehistory.cpp \
    main.cpp \
    player.cpp \
    playergamehistory.cpp \
    ../tui/screen.cpp \
    ../tui/wormtui.cpp \
    ../tui/robottui.cpp \
    ../engines/engine.cpp \
    ../engines/worm.cpp \
    ../engines/robots.cpp \
    playrobot.cpp \
    playworm.cpp \
    ../gtest/googletest/src/gtest-all.cc \
    selectplayer.cpp \
    stats.cpp \
    topplayers.cpp \
    topscores.cpp

HEADERS += \
    additionalscreen.h \
    createplayer.h \
    game.h \
    gamehistory.h \
    player.h \
    playergamehistory.h \
    ../tui/screen.h \
    ../tui/wormtui.h \
    ../tui/robottui.h \
    ../engines/engine.h \
    ../engines/worm.h \
    playrobot.h \
    playworm.h \
    ../engines/robots.h \
    selectplayer.h \
    stats.h \
    topplayers.h \
    topscores.h

INCLUDEPATH += \
../gtest \
../gtest/googletest \
../gtest/googletest/include \
../gtest/googletest/include/gtest

LIBS += -lncurses -lform
