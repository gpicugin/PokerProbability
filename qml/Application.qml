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
        id: _toolBar
        contentHeight: _toolButton.implicitHeight

        Rectangle {
            color: Style.backgroundColorDark
            anchors.fill: parent
            ToolButton {
                id: _toolButton
                anchors.right: parent.right
                property bool isOpened: false
                Text {
                    text: _toolButton.isOpened ? "▶" : "☰"
                    color: "white"
                    anchors.centerIn: parent
                    verticalAlignment:      Qt.AlignVCenter
                    horizontalAlignment:    Qt.AlignHCenter
                    font.pixelSize: Qt.application.font.pixelSize * 3.5
                }


                onClicked: {
                    if(!isOpened)
                    {
                        isOpened = true
                        _drawer.open();
                    }
                    else {
                        isOpened = false
                        _drawer.close();
                    }
                }
            }
        }
    }

    AppDrawer {
        id: _drawer
        height: window.height - header.height
        width: window.width * 0.33
        y: header.height
        edge: Qt.RightEdge        
    }

    MainFrame {
        id: _mainFrame
        height: window.height - header.height
        width: window.width
        Connections {
            target: _drawer

            function onXChanged() {
                _mainFrame.width = _drawer.x
            }
            function onClosed() {
                _mainFrame.width = window.width
            }
        }
        Connections {
            target: window

            function onWidthChanged() {
                if(!_drawer.opened)
                    _mainFrame.width = window.width
            }
        }
    }
}
