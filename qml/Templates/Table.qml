import QtQuick 2.15
import Table 1.0
import "../StyleSettings"

Rectangle
{
    id: root
    color: Style.tableDarkColor
    radius: 300
    border.color: Style.tableBorderColor
    signal indexChanged
    anchors.centerIn: parent
    property alias _tableModel: _tableModel

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




    Item {
        id: _contayner
        anchors {
            centerIn: parent
        }

        height: root.height * 0.33
        width: 500/726 * height * 5.7

        property int cardWidth: 500/726 * height;
        property int space: cardWidth * 0.2;


        ListView {
            id: _tableView
            anchors {
                centerIn: parent
            }
            height: parent.height
            width: parent.width
            orientation: ListView.Horizontal            
            spacing: _contayner.space
            model:  TableModel {
                id: _tableModel
            }
            Connections {
                target: appEngine
                function onTableHasChanged(Card) {
                    _tableModel.add(Card);
                }
                function onTableHasCleared() {
                    _tableModel.clear();
                }
            }
            delegate: Card {
                id: _card
                height: _contayner.height
                url: model.url                
            }
        }
    }
}


