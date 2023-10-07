QT += testlib
QT += qml quick widgets
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    ../../src/CalculatorOfProbability.h \
    ../../src/CardClass.h

SOURCES +=  \
    ../../src/CalculatorOfProbability.cpp \
    ../../src/CardClass.cpp \
    tst_calculatorOfProbability.cpp

include(../../common.pri)
