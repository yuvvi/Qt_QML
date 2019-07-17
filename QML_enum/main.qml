import QtQuick 2.4
import QtQuick.Window 2.2
import MyColorQMLModule 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Enumeration")
    Component.onCompleted: {
        console.log("Color :",MyColors.RED)
        console.log("Color :",MyColors.GREEN)
        console.log("Color :",MyColors.BLUE)
    }
}
