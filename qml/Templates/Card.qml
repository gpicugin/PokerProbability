import QtQuick 2.15
import QtQml 2.15

Rectangle {
    id: root
    height: 300
    width: 500/726 * height
    radius: 6
    border {
        color: "black"
        width: root.height * 0.03
    }
    color: "white"
    property string url;

    Image {
        id: _texture
        anchors.centerIn: parent

        fillMode: Image.Stretch

        height: parent.height * 0.93
        width: 500/726 * height
        source: url
    }
}
