import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Mouse Event")
    Rectangle{
        width: parent.width; height: parent.height
        MouseArea{
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                if(mouse.button == Qt.RightButton){
                    parent.color="blue"
                }else{
                    parent.color="red"
                }
            }
        }
    }
}
