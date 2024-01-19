QT += testlib
QT += core
QT += gui
QT += qml quick widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    src/CalculatorOfProbability.h \
    src/AppEngine.h \
    src/Cards.h \
    src/HandsModel.h \
    src/TableModel.h

SOURCES += \
    src/CalculatorOfProbability.cpp \
    src/AppEngine.cpp \
    src/HandsModel.cpp \
    src/TableModel.cpp \
    src/main.cpp

RESOURCES += \
    qml.qrc

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

DISTFILES += \
    qml/AppDrawer.qml \
    qml/Application.qml \
    qml/ButtonStart.qml \
    qml/MainFrame.qml \
    qml/StyleSettings/StyleSettings.qml \
    qml/StyleSettings/qmldir \
    qml/Templates/Card.qml \
    qml/Templates/Hand.qml \
    qml/Templates/Hands.qml \
    qml/Templates/Table.qml \
    qml/Templates/qmldir \
    qml/resources/menu_button.png



