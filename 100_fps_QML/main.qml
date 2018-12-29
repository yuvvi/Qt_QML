import QtQuick 2.0
import QtQuick.Window 2.2

//import FpsItem

Window {
    visible: true
    width: 480
    height: 320
    title: qsTr("FPS")
    Item{
        width: 480
        height: 320
        Image {
            id: root
            sourceSize.width: parent.width
            sourceSize.height: parent.height
    //        fillMode: Image.PreserveAspectCrop

            Component.onCompleted: {
                height = parent.height
                width = parent.width
            }

            source: "qrc:/clipart12982.png"

            SequentialAnimation {
                running: true
                loops: Animation.Infinite

//                NumberAnimation {
//                    target: root
//                    property: "scale"
//                    from: 0.5
//                    to: 2.0
//                    duration: 30
//                }

//                NumberAnimation {
//                    target: root
//                    property: "scale"
//                    from: 2.0
//                    to: 0.5
//                    duration: 100
//                }
            }
//            NumberAnimation on rotation {
//                id: rAnim
//                from: 0
//                to: 360
//                duration: 5000
//                loops: Animation.Infinite
//            }
        }
    }

    FPSMonitor {
        anchors.top: parent.top
        anchors.left: parent.left
    }
//    FpsItem {
//        id: fpsItem
//        anchors.centerIn: parent
//    }
}
