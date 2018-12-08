import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        width:parent.width; height: parent.height;color: "black"
        Image{
            id:rocket
            x:50; y:150
            source:"qrc:/images/img/rocket_img.jpg"
            transformOrigin: Item.Center
        }
        Keys.onLeftPressed:
            rocket.rotation = (rocket.rotation-10)% 360
        Keys.onRightPressed:
            rocket.rotation = (rocket.rotation+10)%360
        focus: true

    }
}
