import QtQuick 2.12
import QtQuick.Controls
import "../qml/StyleSettings"
import "../qml/Templates"

Rectangle {

    id: root
    color: Style.backgroundColor
    Table
    {
        id: _table
        anchors.centerIn: parent

        width: root.width * 0.7
        height: root.height * 0.5
    }

    Hands
    {
        id: _hands
        anchors.fill: _table
    }

    ButtonStart {
        id: _buttonStart
        anchors.horizontalCenter: root.horizontalCenter
        anchors.bottom: root.bottom

        width: 100
        height: 40
    }

    //width: window.width - _drawer.width

    Connections {
        target: _drawer

        function onXChanged() {
            _mainFrame.width = _drawer.x
        }
    }
}
