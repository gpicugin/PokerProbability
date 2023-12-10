import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Universal
import "../qml/StyleSettings"

ApplicationWindow  {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Poker Analiser")
    color: Style.backgroundColor

    header: ToolBar {

        contentHeight: _toolButton.implicitHeight

        Rectangle {
            color: Style.backgroundColorDark
            anchors.fill: parent
            ToolButton {
                id: _toolButton
                anchors.right: parent.right
                property bool isOpened: false
                text: isOpened ? "▷" : "☰"
                font.pixelSize: Qt.application.font.pixelSize * 1.6

                onClicked: {
                    if(!isOpened) {
                        isOpened = true
                        _drawer.open();
                    }
                    else {
                        isOpened = false
                        _drawer.close();
                    }
                }

                Connections {
                    target: _drawer
                    function onClosed() {
                        _toolButton.isOpened = false
                    }
                }
            }
        }
    }

    AppDrawer {
        id: _drawer

        width: window.width * 0.33
        y: header.height
        height: window.height - header.height
        edge: Qt.RightEdge        
    }

    MainFrame {
        id: _mainFrame
        width: window.width
        height: window.height - header.height
    }
}
