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
    property alias _cardModel: _cardModel

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
        id: _cardModel
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
                centerIn: parent
            }
            height: root.height * 0.33
            width: (_cardModel.count === 1) ? 500/726 * height : _cardModel.count * 500/726 * height + (_cardModel.count - 1) * 500/726 * height * 0.2
            spacing: parent.height * 500/726 * 0.2
            orientation: ListView.Horizontal
            model: _cardModel

            delegate: Card {
                id: _delegte
                height: root.height * 0.33
            }
        }
    }

    function getNextTableCard()
    {
        _cardModel.append({stateOfCard: GameManager.getCurrentCardName()})
    }
    function clearTable()
    {
        _cardModel.clear()
    }

}


