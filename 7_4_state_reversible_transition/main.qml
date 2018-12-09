import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 250
    height: 75
    title: qsTr("State Condition")
    Rectangle{
        width:parent.width; height: parent.height;color: "#ccffcc"
        state: "without text"
        TextInput{
            id: text_field
            text:"Enter text...."
            Image {
                id: clear_button
                source: "qrc:/img/clear.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: text_field.text = " "
                }
            }
        }
        states:[
            State{
                name: "with text"
                when:text_field.text != " "
                PropertyChanges {target: clear_button; opacity:1.0}
            },
            State{
                name:"without text"
                when: text_field.text == " "
                PropertyChanges {target: clear_button; opacity:0.25}
                PropertyChanges {target: text_field; focus: true}
            }
        ]
        transitions:[
            Transition{
                from:"with text"; to: "without text"
                reversible:true
                PropertyAnimation{target:clear_button; properties:"opacity"; duration: 1000}
            }

        ]
    }


}
