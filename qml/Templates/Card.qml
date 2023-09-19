import QtQuick 2.15
import QtQml 2.15

Rectangle {

//    Connections {
//        target: Table
//        function
//    }

    id: root
    height: 300
    width: 500/726 * height
    radius: 6
    border {
        color: "black"
        width: root.height * 0.03
    }
    color: "white"
    property int index: 52

    state: stateOfCard

    function setState() {
        console.log("hello_2")
        console.log(index)

        stateOfCard = states[index].name
    }

    states: [

        State { name: "clubs_2"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/2_of_clubs.png"
                }},
        State { name: "clubs_3"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/3_of_clubs.png"
                }},
        State { name: "clubs_4"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/3_of_clubs.png"
                }},
        State { name: "clubs_5"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/5_of_clubs.png"
                }},
        State { name: "clubs_6"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/6_of_clubs.png"
                }},
        State { name: "clubs_7"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/7_of_clubs.png"
                }},
        State { name: "clubs_8"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/8_of_clubs.png"
                }},
        State { name: "clubs_9"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/9_of_clubs.png"
                }},
        State { name: "clubs_10"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/10_of_clubs.png"
                }},
        State { name: "clubs_jack"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/jack_of_clubs.png"
                }},
        State { name: "clubs_queen"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/queen_of_clubs.png"
                }},
        State { name: "clubs_king"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/king_of_clubs.png"
                }},
        State { name: "clubs_ace"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/ace_of_clubs.png"
                }},
        //-------------------------------------------------//

        State { name: "diamonds_2"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/2_of_diamonds.png"
                }},
        State { name: "diamonds_3"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/3_of_diamonds.png"
                }},
        State { name: "diamonds_4"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/3_of_diamonds.png"
                }},
        State { name: "diamonds_5"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/5_of_diamonds.png"
                }},
        State { name: "diamonds_6"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/6_of_diamonds.png"
                }},
        State { name: "diamonds_7"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/7_of_diamonds.png"
                }},
        State { name: "diamonds_8"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/8_of_diamonds.png"
                }},
        State { name: "diamonds_9"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/9_of_diamonds.png"
                }},
        State { name: "diamonds_10"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/10_of_diamonds.png"
                }},
        State { name: "diamonds_jack"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/jack_of_diamonds.png"
                }},
        State { name: "diamonds_queen"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/queen_of_diamonds.png"
                }},
        State { name: "diamonds_king"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/king_of_diamonds.png"
                }},
        State { name: "diamonds_ace"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/ace_of_diamonds.png"
                }},
        //-------------------------------------------------//

        State { name: "hearts_2"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/2_of_hearts.png"
                }},
        State { name: "hearts_3"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/3_of_hearts.png"
                }},
        State { name: "hearts_4"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/3_of_hearts.png"
                }},
        State { name: "hearts_5"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/5_of_hearts.png"
                }},
        State { name: "hearts_6"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/6_of_hearts.png"
                }},
        State { name: "hearts_7"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/7_of_hearts.png"
                }},
        State { name: "hearts_8"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/8_of_hearts.png"
                }},
        State { name: "hearts_9"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/9_of_hearts.png"
                }},
        State { name: "hearts_10"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/10_of_hearts.png"
                }},
        State { name: "hearts_jack"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/jack_of_hearts.png"
                }},
        State { name: "hearts_queen"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/queen_of_hearts.png"
                }},
        State { name: "hearts_king"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/king_of_hearts.png"
                }},
        State { name: "hearts_ace"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/ace_of_hearts.png"
                }},
        //-------------------------------------------------//

        State { name: "spades_2"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/2_of_spades.png"
                }},
        State { name: "spades_3"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/3_of_spades.png"
                }},
        State { name: "spades_4"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/3_of_spades.png"
                }},
        State { name: "spades_5"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/5_of_spades.png"
                }},
        State { name: "spades_6"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/6_of_spades.png"
                }},
        State { name: "spades_7"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/7_of_spades.png"
                }},
        State { name: "spades_8"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/8_of_spades.png"
                }},
        State { name: "spades_9"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/9_of_spades.png"
                }},
        State { name: "spades_10"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/10_of_spades.png"
                }},
        State { name: "spades_jack"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/jack_of_spades.png"
                }},
        State { name: "spades_queen"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/queen_of_spades.png"
                }},
        State { name: "spades_king"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/king_of_spades.png"
                }},
        State { name: "spades_ace"; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/ace_of_spades.png"
                }},


        State { name: "shirt_card" ; PropertyChanges {
                target: _texture
                source: "qrc:/Cards/red_joker.png"
                }}
    ]

    Image {
        id: _texture
        anchors.centerIn: parent



        fillMode: Image.Stretch

        height: parent.height * 0.93
        width: 500/726 * height
    }
}
