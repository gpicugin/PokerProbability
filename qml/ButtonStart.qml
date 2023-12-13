import QtQuick 2.12
import QtQuick.Controls 2.12

Button {    
    property int counter: 0
    text: "Start"
    onClicked: {
        appEngine.doNextStep();
    }
}
