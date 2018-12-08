import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Dragging_elements ")
    Rectangle{
        id:rect; width:parent.width; height: parent.height
        Image{
            id:pic; source: "qrc:/images/img/smily.png"
            opacity: (600 - pic.x)/600;
        }
        MouseArea{
            anchors.fill:parent
            drag.target: pic
            drag.axis: Drag.Xaxis
            drag.minimumX: 0
            drag.maximumX: rect.width - pic.width
        }
    }

}
