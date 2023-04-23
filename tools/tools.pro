TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        configuration.cpp \
        log.cpp \
        main.cpp

HEADERS += \
    configuration.h \
    log.h \
    macro.h \
    macros.h

DISTFILES += \
    log.txt \
    log2.txt
