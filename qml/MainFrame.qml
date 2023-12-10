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

    Hand
    {
        id: _hand
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: _table.bottom
        }
        visible: false

        height: _table.height * 0.33
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
