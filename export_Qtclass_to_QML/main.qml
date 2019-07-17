import QtQuick 2.9
import QtQuick.Window 2.2

import ApplnLayer 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Import Qt class & object")
    Applyr_comp{
        id: applObj
        onPrintCountChanged: {
            console.log("onPrintcountChanged :: ",pCount,printCountQML)
        }
    }

    Component.onCompleted: {
        console.log("main.qml #Component.onCompleted#START")
        /*Class is imported*/
        applObj.print_operation()
        applObj.pCount = 2
        applObj.printCountQML = 4
        /*Object is imported*/
        appObj.printCountQML = 5
        console.log("main.qml #Component.onCompleted#END")
    }
}
