import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 420
    height: 680
    title: qsTr("Hello World")
    //Grid layout
    Grid{
        id: grid_lyt
        columns: 3
        spacing: 2
        Rectangle{id:rec1;color:'red';width:100;height:100}
        Rectangle{id:rec2;color:'green';width:100;height:100}
        Rectangle{id:rec3;color:'blue';width:100;height:100}
        Rectangle{id:rec4;color:'yellow';width:100;height:100}
    }

    Rectangle{
        id: separator
        width:parent.width
        height:5
        color:'black'
        anchors.top:grid_lyt.bottom
    }
    //Row layout
    Row{
        id: row_lyt
        spacing:2
        Rectangle{id:rec5;color:'green';width:100;height:100}
        Rectangle{id:rec6;color:'blue';width:100;height:100}
        Rectangle{id:rec7;color:'yellow';width:100;height:100}
        Rectangle{id:rec8;color:'red';width:100;height:100}
        anchors.top:separator.bottom
    }
    Rectangle{
        id: separator2
        width:parent.width
        height:5
        color:'black'
        anchors.top:row_lyt.bottom
    }
    //Column layout
    Column{
        id: column_lyt
        spacing:2
        Rectangle{id:rec9;color:'green';width:100;height:100}
        Rectangle{id:rec10;color:'blue';width:100;height:100}
        Rectangle{id:rec11;color:'yellow';width:100;height:100}
        Rectangle{id:rec12;color:'red';width:100;height:100}
        anchors.top:separator2.bottom
    }
}
