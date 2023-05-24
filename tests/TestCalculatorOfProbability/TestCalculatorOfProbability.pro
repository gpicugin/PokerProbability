QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    ../../src/CalculatorOfProbability.h

SOURCES +=  \
    ../../src/CalculatorOfProbability.cpp \
    tst_calculatorOfProbability.cpp

include(../../common.pri)
