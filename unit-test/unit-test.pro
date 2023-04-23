TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += main.cpp
### add the following lines
# if you have pthread errors, comment/uncomment the next line
LIBS += -pthread
SOURCES += ../gtest/googletest/src/gtest-all.cc
INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest
HEADERS += ../tools/configuration.h
SOURCES += ../tools/configuration.cpp
HEADERS += ../tools/log.h
SOURCES += ../tools/log.cpp
### add any other source or header files you may need
