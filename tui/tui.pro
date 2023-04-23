TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt


unix:LIBS += -lncurses

SOURCES += \
        main.cpp \
        screen.cpp \
        ../engines/worm.cpp \
        ../engines/engine.cpp \
        ../engines/robots.cpp \
        wormtui.cpp \
        robottui.cpp


HEADERS += \
    robottui.h \
    screen.h \
    worm.h \
    engine.h \
    robots.h \
    wormtui.h
