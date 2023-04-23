QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    asgui.cpp \
    ../engines/engine.cpp \
    ../engines/worm.cpp \
    ../engines/robots.cpp \
    newplayer.cpp \
    pagestack.cpp \
    selectplayer.cpp \
    statistics.cpp \
    topgames.cpp \
    topplayers.cpp \
    wormgui.cpp \
    robotgui.cpp \
    ../info_bank/player.cpp \
    ../info_bank/game.cpp \
    ../info_bank/playergamehistory.cpp \
    ../info_bank/gamehistory.cpp

HEADERS += \
    asgui.h \
../engines/engine.h \
    ../engines/worm.h \
    ../engines/robots.h \
    newplayer.h \
    pagestack.h \
    selectplayer.h \
    statistics.h \
    topgames.h \
    topplayers.h \
    wormgui.h \
    robotgui.h \
    ../info_bank/player.h \
    ../info_bank/game.h \
    ../info_bank/playergamehistory.h \
    ../info_bank/gamehistory.h


FORMS += \
    asgui.ui \
    newplayer.ui \
    selectplayer.ui \
    statistics.ui \
    topgames.ui \
    topplayers.ui \
    wormgui.ui \
    robotgui.ui

TRANSLATIONS += \
    AsGui_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
