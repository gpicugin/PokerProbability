import QtQuick 2.15
import "../StyleSettings"

Rectangle
{
    id: root
    color: Style.tableDarkColor
    radius: 300
    border.color: Style.tableBorderColor
    signal indexChanged
    anchors.centerIn: parent


    width: 300
    height: 100

    border.width: 10
    gradient: Gradient {
        GradientStop {
            position: 0
            color: Style.tableDarkColor
        }

        GradientStop {
            position: 0.33
            color: Style.tableLightColor
        }

        GradientStop {
            position: 0.66
            color: Style.tableLightColor
        }

        GradientStop {
            position: 1
            color: Style.tableDarkColor
        }
        orientation: Gradient.Vertical
    }

    ListModel {
        id: cardModel        
    } 


    Item {

        anchors {
            centerIn: parent
        }

        height: root.height * 0.33
        width: 500/726 * height * 7

        ListView {
            id: cardView
            anchors {
                fill: parent
            }
            spacing: parent.height * 500/726 / 7
            orientation: ListView.Horizontal
            model: cardModel

            delegate: Card {
                id: _delegte
                height: root.height * 0.33
            }
        }
    }


    Rectangle {
        id: button

        width: 100
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: root.bottom
        border {
            color: "white"
            width: 1
        }

        Text {
            anchors.centerIn: parent
            renderType: Text.NativeRendering
            text: "Add"
        }

         MouseArea {
             anchors.fill: parent
             property int counter: 0
             onClicked: {

                if(counter == 5) {
                    counter = 0
                    cardModel.clear()
                    return
                }

                cardModel.append({stateOfCard: "clubs_" + (counter + 2)})
                console.log(cardModel.get(counter).index)




                counter = counter + 1;
            }
        }
    }
 }

