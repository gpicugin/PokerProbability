import QtQuick 2.12
import QtQuick.Controls
import Qt.labs.qmlmodels
import "../qml/StyleSettings"

Drawer {

    Rectangle {

        id: root
        anchors.fill: parent
        color: Style.backgroundColorDark

        TableView {

            anchors.fill: parent
            columnSpacing: 1
            rowSpacing: 1
            clip: true
            model: TableModel {
                TableModelColumn {display: "combo"}
                TableModelColumn {display: "probability"}

                rows: [
                {
                    "combo":        "High Card",
                    "probability":  "0.0"
                },
                {
                    "combo":        "One Pair",
                    "probability":  "0.0"
                },
                {
                    "combo":        "Two Pairs",
                    "probability":  "0.0"
                },
                {
                    "combo":        "Set",
                    "probability":  "0.0"
                },
                {
                    "combo":        "Street",
                    "probability":  "0.0"
                },
                {
                    "combo":        "Flash",
                    "probability":  "0.0"
                },
                {
                    "combo":        "Full House",
                    "probability":  "0.0"
                },

                {
                    "combo":        "Square",
                    "probability":  "0.0"
                },
                {
                    "combo":        "Street Flash",
                    "probability":  "0.0"
                },
                {
                    "combo":        "Flash Royal",
                    "probability":  "0.0"
                }
            ]

            }
            delegate: Rectangle {

                color: Style.backgroundColorDark
                implicitWidth: root.width / 2 - 5
                implicitHeight: root.height / 10 - 1
                border.width: 1
                border.color: "white"
                Text {
                    color: "white"
                    text: display
                    anchors.centerIn: parent
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: root.width / 12
                }
            }
        }
    }
}
