import QtQuick 2.8
import QtQuick.Window 2.2
/*
    Green reactangular area on the screen
    window :The Window object creates a new top-level window for a Qt Quick scene.
    Rectangle: Without top level window, rectangle cannot be shown
    objects : window & rectangle
    properties & value binding: visible: true, width: 640
*/
Window {
    visible: true
    width: 640
    height: 480
    Rectangle{
        width: 350
        height: 2*100
        color:"light green"
    }
    Text{
        id: label               //IDENTITY PROPERTY -gives the element a name
        text: "Welcome to QML"  //STANDARD PROPERTY -to assign a value
        height: 50              //STANDARD PROPERTY
        font.family: "Helvatica"//GROUPED PROPERTY -keep related properties together
        font.pixelSize: 24      //GROUPED PROPERTYll
    }
}
