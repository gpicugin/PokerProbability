import QtQuick 2.12
import QtQuick.Controls 2.12

Button {    
    property int counter: 0
    text: "Start"
    onClicked: {
        if(counter == 0)
        {
            _hand.getHand()
            _hand.visible = true
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
            _hand.visible = false
        }
    }
}
