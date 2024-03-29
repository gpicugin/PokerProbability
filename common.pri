PROJECT_ROOT_PATH = $${PWD}

win32: OS_SUFFIX = win32
linux-g++: OS_SUFFIX = linux

CONFIG(debug, debug | release) {
    BUILD_FLAG = debug
    LIB_SUFFIX = d
} else {
    BUILD_FLAG = release
}

LIBS_PATH = $${PROJECT_ROOT_PATH}/lib.$${OS_SUFFIX}
INC_PATH = $${PROJECT_ROOT_PATH}/include
IMPORT_PATH = $${PROJECT_ROOT_PATH}/import
BIN_PATH = $${PROJECT_ROOT_PATH}/bin/$${BUILD_FLAG}

BUILD_PATH = $${PROJECT_ROOT_PATH}/build/$${BUILD_FLAG}/$${TARGET}
RCC_DIR = $${BUILD_PATH}/rcc
UI_DIR = $${BUILD_PATH}/ui
MOC_DIR = $${BUILD_PATH}/moc
OBJECTS_DIR = $${BUILD_PATH}/obj

LIBS += -L$${LIBS_PATH}
INCLUDEPATH += $${INC_PATH}
INCLUDEPATH += $${IMPORT_PATH}
INCLUDEPATH += $${PWD}/src
QML_DIR = $${PWD}/qml
DESTDIR = $${BIN_PATH}
CONFIG -= debug_and_release
CONFIG -= debug_and_release_target
QMAKE_LFLAGS_CONSOLE = -Wl,-subsystem,windows

