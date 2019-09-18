include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../../src/flow.h \
        ../../src/model.h \
        ../../src/system.h \
        ../myflow.h \
        functional_tests.h

SOURCES += \
        ../../src/flow.cpp \
        ../../src/model.cpp \
        ../../src/system.cpp \
        main.cpp \
        ../myflow.cpp \
        functional_tests.cpp
