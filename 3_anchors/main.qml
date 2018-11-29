import QtQuick 2.8
import QtQuick.Window 2.2
/*
  Each QML item be thought of as having 6 invisible anchor & 4 margin lines.
  Anchors used to specify relative positions of items, as well as offsets & margins.
  Used to control size of an item.
*/
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Anchors")

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
        anchors.leftMargin: 5
    }
}
