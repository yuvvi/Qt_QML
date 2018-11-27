import QtQuick 2.8
import QtQuick.Window 2.2


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Image")

    Rectangle{
        width: parent.width //BINDING PROPERTY VALUES-automatically updated
        height: 2*100
        color: "light green"
        Image {
            id: img
            source: "qrc:/images/images/tech_img.png"
        }
    }

}
