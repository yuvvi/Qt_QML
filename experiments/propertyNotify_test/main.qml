import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var myText : notify.myStrData
    property bool isOC : notify ? notify.isOverclock:false
    Connections{
        target : notify

        onOverclockCPU:{
            console.log("QML ----- TIMER TRIGGERED---onOverclockCPUed");
        }
        onMyTimerTriggered:{
            console.log("QML ----- TIMER TRIGGERED");
        }
    }

    Timer{
        id: testTimer
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            console.log("test timer triggered #isOC:",isOC);
        }
    }

    Rectangle{
        width: 100
        height: 100
        color: "red"
        Text {
            anchors.centerIn: parent.Center

            id: name
            text: notify.myStrData
        }
    }

    Component.onCompleted: {

    }
}
