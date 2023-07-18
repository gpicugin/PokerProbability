import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
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
    
    Hand
    {
        id: _hand
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: _table.bottom
        }

        height: _table.height * 0.33
    }

    Button {
        id: _button

        width: 100
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: root.top
        property int counter: 0
        onClicked: {
            if(counter == 0)
            {
                _hand.getHand()
                counter += 2
            }
            else if(counter == 2)
            {
                _table.getNextTableCard()
                _table.getNextTableCard()
                _table.getNextTableCard()
                counter +=3
            }
            else if(counter == 5)
            {
                _table.getNextTableCard()
                counter++
            }
            else if(counter == 6)
            {
                _table.getNextTableCard()
                counter++
            }
            else {
                _table.clearTable()
                counter = 0
            }

        }
    }
}
