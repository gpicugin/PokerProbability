QT += quick
QT += testlib
QT += qml quick widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    src/CalculatorOfProbability.h

SOURCES += \
    src/CalculatorOfProbability.cpp \
    src/main.cpp

OTHER_FILES +=
    translations/*.ts

OTHER_FILES += \
    qml/main.qml


TRANSLATIONS += \
    translations/PokerProbability_ru_RU.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH +=

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(common.pri)

DEFINES += QT_QML_DEBUG_NO_WARNING

QMAKE_POST_LINK += windeployqt.exe --qmldir $$QML_DIR $$DESTDIR/PokerProbabilityApp.exe

