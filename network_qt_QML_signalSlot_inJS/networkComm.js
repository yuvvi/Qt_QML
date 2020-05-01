function get_NWObject(root) {
    var comp, compobj;
    comp = Qt.createComponent("netwrk2.qml");
    compobj = comp.createObject(root);
    return compobj;
}

function getRequestJS(http_obj, url){
    http_obj.rxPayload.connect(responseData); /*rxPayload signal connects to responseData*/
    http_obj.getRequest(url);
}

/*signal - onRxPayload(int stts)*/
function responseData(status){

    console.log("responseData #status :"+status)
    nci.rxPayload.disconnect(responseData); /*rxPayload signal disconnects to responseData*/
}

