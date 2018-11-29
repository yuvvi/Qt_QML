import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Anchors 3_1")
    Rectangle{
        id: rect1
        color:'red'
        width: parent.width/2
        height: parent.height/2

    }
    Rectangle{
        id: rect2
        color:'blue'
        width: parent.width/2
        height: parent.height/2
        anchors.left: rect1.right
        anchors.top: rect1.bottom
    }


}
