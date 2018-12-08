import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Raw Keyboard")
    /*
    Item{
        focus:true
        Keys.onPressed: {
            if(event.key === Qt.Key_Left){
                console.log("move Left");
                event.accepted= true;
            }
        }
    }*/
    Item{
        focus: true
        Keys.onLeftPressed:
            console.log("move left -2 ")
    }
}
