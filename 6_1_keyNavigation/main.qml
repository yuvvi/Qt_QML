import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("KEY NAVIGATION")
    Rectangle{
        width: parent.width; height: parent.height; color: "black"
        Rectangle{
            id: leftRect
            x:25; y:25; width: 150; height: 150
            color: focus ? "red":"darked"
            KeyNavigation.right: rightRect
            focus: true
        }
        Rectangle{
            id: rightRect
            x:175; y:25; width: 150; height:150
            color:focus ? "#00ff00":"darked"
            KeyNavigation.left: leftRect
            focus:true
        }
    }


}
