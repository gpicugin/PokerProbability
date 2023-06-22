import QtQuick 2.12
import QtQuick.Window 2.12
import "../qml/StyleSettings"
import "../qml/Templates"

Window {
    id: root
    width: 1080
    height: 960
    visible: true
    title: qsTr("Poker Analiser")
    color: Style.backgroundColor

    Table
    {
        id: _table
        anchors.centerIn: parent

        width: root.width * 0.7
        height: root.height * 0.5        
    }

//    Card {
//        anchors.centerIn: _table
//        height: _table.height * 0.3
//    }
}
