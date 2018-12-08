import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Column{
    TextInput{
        id: name_field
        color: "red"
        focus: true
        KeyNavigation.tab: address_field
    }
    TextInput{
        id: address_field
        color: "blue"
        focus: true
        KeyNavigation.tab: name_field
    }
    }
}
