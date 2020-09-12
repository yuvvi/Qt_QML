import QtQuick 2.4
import QtQuick.Window 2.2
import Qt.example.cppSingleton 1.0

Window {
    visible: true
    width: 100
    height: 100
    Component.onCompleted: {
        console.log(""+ MySingleton.getData());
        MySingleton.setData("Welcome to QML call of cpp singleton")
        console.log(""+ MySingleton.getData());
    }
}
