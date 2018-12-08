import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("MouseArea Clickable")
    color:"lightblue"
    Text{
        id: txt
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text:"Dont Touch me";font.pixelSize: 48
        MouseArea{
            anchors.fill: parent
            onPressed: parent.color="red";
            onReleased:  parent.color="green";
        }
    }
}
