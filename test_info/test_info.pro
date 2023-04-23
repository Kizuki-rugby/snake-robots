TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../info_bank/additionalscreen.cpp \
    ../info_bank/createplayer.cpp \
    ../info_bank/game.cpp \
    ../info_bank/gamehistory.cpp \
    main.cpp \
    ../info_bank/player.cpp \
    ../info_bank/playergamehistory.cpp \
    ../tui/screen.cpp \
    ../tui/wormtui.cpp \
    ../tui/robottui.cpp \
    ../engines/engine.cpp \
    ../engines/worm.cpp \
    ../engines/robots.cpp \
    ../info_bank/playrobot.cpp \
    ../info_bank/playworm.cpp \
    ../gtest/googletest/src/gtest-all.cc \
    ../info_bank/selectplayer.cpp \
    ../info_bank/topscores.cpp \
    ../info_bank/topplayers.cpp \
    ../info_bank/stats.cpp

HEADERS += \
    ../info_bank/additionalscreen.h \
    ../info_bank/createplayer.h \
    ../info_bank/game.h \
    ../info_bank/gamehistory.h \
    ../info_bank/player.h \
    ../info_bank/playergamehistory.h \
    ../tui/screen.h \
    ../tui/wormtui.h \
    ../tui/robottui.h \
    ../engines/engine.h \
    ../engines/worm.h \
    ../info_bank/playrobot.h \
    ../info_bank/playworm.h \
    ../engines/robots.h \
    ../info_bank/selectplayer.h \
    ../info_bank/topscores.h \
    ../info_bank/topplayers.h \
    ../info_bank/stats.h

INCLUDEPATH += \
../gtest \
../gtest/googletest \
../gtest/googletest/include \
../gtest/googletest/include/gtest

LIBS += -lncurses -lform
