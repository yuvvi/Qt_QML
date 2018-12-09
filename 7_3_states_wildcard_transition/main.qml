import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 150
    height: 250
    title: qsTr("State")
    Rectangle{
        state: "stop"
        width: parent.width;height: parent.height;
        focus: true
        Rectangle{
            id:stop_light
            x:25; y:15; width: 100;height: 100
            color:"black"
        }
        Rectangle{
            id:go_light
            x:25; y:135; width: 100;height: 100
            color:"black"
        }
        states: [
            State {
                name: "stop"
                PropertyChanges {target: stop_light; color: "red"}
                PropertyChanges {target: go_light; color: "black"}
            },
            State{
                name:"go"
                PropertyChanges {target: stop_light; color: "black"}
                PropertyChanges {target: go_light; color: "green"}
            }
        ]
        transitions:[
            Transition{
                from: "*"; to:"*"
                //reversible: true
                PropertyAnimation{target:stop_light; properties: "color"; duration: 1200}
                PropertyAnimation{target:go_light; properties: "color"; duration: 1200}
            }
        ]
        MouseArea{
            anchors.fill: parent
            onClicked: parent.state == "stop"? parent.state="go":parent.state="stop"
        }
    }
}
