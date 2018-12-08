import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Mouse Hover")
Rectangle{
    width: parent.width; height: parent.height
    Rectangle{
        x:150; y:50; width:100; height: 100
        color: mouse_area.containsMouse ? "red": "green"
        MouseArea{
            id: mouse_area
            anchors.fill: parent
            hoverEnabled: true
        }
    }
}

}
