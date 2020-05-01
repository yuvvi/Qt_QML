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
        nci.setRouteURL("www.google.com");
        nci.postRequest("");

    }
    Connections{
        target: nci
        onRxPayload:{
//            console.log("onRxPayload #status : "+ stts +" #payload :"+payload );
            console.log("onRxPayload #status : "+ stts);
        }
        /*Used to read payload, QString wont be sufficient for all payloads.
          QByteArray can be convert arrayBuffer only after Qt5.8.
          response signal finished(QNetworkReply*) this cant be received at QML.
        */
        onRxPayload_string:{
            console.log("onRxPayload_string #payload : "+ payload);
        }
        /*Used to read json*/
        onRxPayload_json:{
            console.log("onRxPayload_json #json : "+ jsondata.target);
//            var obj = JSON.parse(jsondata);
//            "target": "KChannel",
//                "appMode": "disconnected",
//                "uiState": "fullScreen",
//                "metadata": {
            console.log(jsondata.target);
            // expected output: 42

            console.log(jsondata.appMode);
            // expected output: true

        }
    }
}
