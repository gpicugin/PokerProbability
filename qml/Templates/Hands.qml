import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Hands 1.0


Item {
    id: root
    PathView {
        id: _handsView
        anchors.fill: parent
        model: HandsModel {
            id: _handsModel

        }

        path: Path {
            startX: root.width / 2
            startY: root.height

            PathCurve { x: root.width;      y: root.height / 2 }
            PathCurve { x: root.width / 2;  y: 0 }
            PathCurve { x: 0;               y: root.height / 2 }
            PathCurve { x: root.width / 2;  y: root.height }
        }        

        delegate: Hand {
            height: root.height / 4            
            url1: model.firstCardURL
            url2: model.secondCardURL
        }
    }

    Connections {
        target: appEngine
        function onNewHand(url1, url2)
        {
            _handsModel.add(url1, url2)
        }
        function onTableHasCleared() {
            _handsModel.clear()
        }
    }
}
