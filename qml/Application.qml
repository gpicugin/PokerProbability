import QtQuick 2.12
import QtQuick.Window 2.12
import "../qml/StyleSettings"


Window {
    id: root
    width: 1080
    height: 960
    visible: true
    title: qsTr("Poker Analiser")
    color: Style.backgroundColor

    Rectangle
    {
        id: _table
        color: Style.tableDarkColor
        radius: 300
        border.color: Style.tableBorderColor

        anchors.centerIn: parent


        width: root.width * 0.7
        height: root.height * 0.5

        border.width: 10
        gradient: Gradient {
            GradientStop {
                position: 0
                color: Style.tableDarkColor
            }

            GradientStop {
                position: 0.5
                color: Style.tableLightColor
            }

            GradientStop {
                position: 1
                color: Style.tableDarkColor
            }
            orientation: Gradient.Vertical
        }

    }
}
