import QtQuick 2.15

Item {
    id: root
    height: 300
    width: 500/726 * height * 2
    Card {
        id: _card1
        anchors {
            left: root.left
            right: root.horizontalCenter
            rightMargin: root.width * 0.025
            top: root.top
            bottom: root.bottom
        }
    }

    Card {
        id: _card2
        anchors {
            left: root.horizontalCenter
            leftMargin: root.width * 0.025
            right: root.right
            top: root.top
            bottom: root.bottom
        }
    }

    function getHand() {
        _card1.state = GameManager.getCurrentCardName()
        _card2.state = GameManager.getCurrentCardName()

    }

    function clearHand() {

    }
}
