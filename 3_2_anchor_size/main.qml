import QtQuick 2.8
import QtQuick.Window 2.2
/*
  Anchors can also used to control the size of an item
*/
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Anchor 3_2")
    Rectangle{
        id: rect1
        x:0
        color:'red'
        width: parent.width/3
        height: parent.height/3

    }
    Rectangle{
        id: rect2
        color:'blue'
        width: parent.width/3
        height: parent.height/3
        anchors.left: rect1.right
        anchors.right: rect3.left
    }
    Rectangle{
        id: rect3
        x:400
        color:'yellow'
        width: parent.width/3
        height: parent.height/3
    }
}
