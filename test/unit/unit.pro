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
        unit_flow.h \
        unit_model.h \
        unit_system.h \
        unit_tests.h

SOURCES += \
        ../../src/flow.cpp \
        ../../src/model.cpp \
        ../../src/system.cpp \
        ../myflow.cpp \
        main.cpp \
        unit_flow.cpp \
        unit_model.cpp \
        unit_system.cpp \
        unit_tests.cpp
