import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Anchor Exercise")

    Rectangle{
        id: rect1
        width:parent.width - 100
        height:parent.height/2-50
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.leftMargin: 50
        color:'red'
    }
    Rectangle{
        id: rect1_2
        width:rect1.width/3
        height: rect1.height/2
        anchors.left: rect1.left
        anchors.verticalCenter: rect1.verticalCenter
        anchors.leftMargin: 100
    }

}
