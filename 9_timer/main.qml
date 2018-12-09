import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Timer")
    Rectangle{
        width: parent.width; height:parent.height
        Text{
            id:time_obj
            text : Date().toString()
        }
    }
    Timer{
        interval: 500;
        running: true
        repeat:true
        onTriggered: time_obj.text = Date().toString()
    }

}
