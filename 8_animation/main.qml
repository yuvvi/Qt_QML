import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400
    height: 400
    title: qsTr("Animation")
    Rectangle{
        id: rect
        width: 120; height: 200
        Image{
            id: img
            source: "qrc:/image/qt-1-555150.png"
            x: 60 - img.width /2
            y:0
            SequentialAnimation on y{
                running: true; loops: Animation.Infinite
                NumberAnimation{to: 200-img.height; easing.type: "OutBounce"; duration:2000}
                PauseAnimation {duration: 1000}
                NumberAnimation{to: 0; easing.type: "OutQuad"; duration: 1000}
            }
        }
    }
}
