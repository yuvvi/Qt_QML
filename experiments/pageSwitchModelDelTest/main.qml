import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property bool switchSource : true
    Rectangle{
        width: 300
        height: 300
        color: "blue"
        Column{
            width: parent.width
            height: parent.height
        MouseArea{
            width: parent.width/2
            height: parent.height/2
            onClicked: {
                console.log("Onclicked")
                if(switchSource){
                    pageLoader.source= ""
                    switchSource = false;
                }else{
                    pageLoader.source= "qrc:/TuningPage.qml"
                    switchSource = true;
                }
            }
        }
        Loader{
            id: pageLoader
            source: "qrc:/TuningPage.qml"
            onLoaded: {
                console.log("Page loaded :",source);
            }
        }
        }
    }
}
//mymdl
