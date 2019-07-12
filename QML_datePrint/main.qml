import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Timer{
        id : test_tmr
        interval: 60000/2
        onTriggered:  {
            var tmr_tgr_time = new Date()
            console.log("timer interval :", test_tmr.interval)
            console.log("11072019_1527#TIMER_TRIGGER#TEST_TIMER# epoch :",tmr_tgr_time.getTime().valueOf(), " #",Qt.formatDateTime(tmr_tgr_time, "ddMMyyyy#HH:MM:ss:zzz"))
            test_tmr.interval = 1*60000
            console.log("timer interval 2:", test_tmr.interval)
            test_tmr.start()
        }
    }

    Component.onCompleted: {
        test_tmr.start()
        console.log("timer interval :", test_tmr.interval)
        var today = new Date()
        console.log(" :",Qt.formatDateTime(today, "ddMMyyyy#HH:MM:ss:zzz"), " epoch# ",today.getTime().valueOf());
    }
}
