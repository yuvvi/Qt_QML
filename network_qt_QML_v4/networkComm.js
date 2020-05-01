
function get_NWObject(root) {
    var comp, compobj;
    comp = Qt.createComponent("netwrk2.qml");
    compobj = comp.createObject(root);
    return compobj;
}

