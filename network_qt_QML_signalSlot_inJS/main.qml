import QtQuick 2.2
import QtQuick.Window 2.2
import com.network.xyz 1.0

import "./networkComm.js" as Handlinghttp

Window {
    id:root
    visible: true
    width: 440
    height: 280
    property NetworkComm nci:null;
    title: qsTr("QML network operations")

    Component.onCompleted: {
        console.log("component.onCompleted")
        nci = Handlinghttp.get_NWObject(root);
        Handlinghttp.getRequestJS(nci,"www.google.com");
    }
}
