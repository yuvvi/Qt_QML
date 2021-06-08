import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Column{
        anchors.fill: parent.centerIn
//        width: parent.width
//        height: parent.height
        Rectangle{
            width: 600
            height: 200
            color: "green"
        }
        Loader{
//            source: ld_rect
            sourceComponent: ld_rect
        }

    }
    Component{
        id: ld_rect
        Rectangle{
            width: 600
            height: 100
            color: "red"
        }
    }
}
