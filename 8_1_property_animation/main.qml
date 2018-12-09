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
            MouseArea{
                anchors.fill: parent
                onClicked: animation_obj.start()
            }
        }
        PropertyAnimation{
            id:animation_obj
            target: img
            property: "scale"
            from: 1; to:5
        }
    }
}
