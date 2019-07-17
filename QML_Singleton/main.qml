import QtQuick 2.9
import QtQuick.Window 2.2
import "qrc:///Color"

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
        color: CompColor.redcolour
    }
    My_Rectangle{

    }
}
