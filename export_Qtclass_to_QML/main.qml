import QtQuick 2.9
import QtQuick.Window 2.2

import ApplnLayer 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Applyr_comp{
        id: applObj
        onPrintCountChanged: {
            console.log("onPrintcountChanged :: ",pCount,m_printCount)
        }
    }

    Component.onCompleted: {
        console.log("main.qml #Component.onCompleted#START")
        /*Class is imported*/
        applObj.print_operation()
        applObj.pCount = 2
        applObj.m_printCount = 4
        /*Object is imported*/
        appObj.m_printCount = 5
        console.log("main.qml #Component.onCompleted#END")
    }
}
