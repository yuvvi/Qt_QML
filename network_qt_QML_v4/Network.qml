import QtQuick 2.0

Item {
    id: networkID

    Component.onCompleted: {
        console.log("Network component created.")
        request("http://10.197.36.2:8081/ctap/init?locallyServed=true","POST",processPost);
//        request("http://10.197.36.2:8081/ctap/init","POST",processPost);
    }

    function request(url, method, callback, body, isREFCall){
        console.log("Function request")
        var http = new XMLHttpRequest();
        http.open(method, url, true);
        // Send the proper header information along with the request
//        http.setRequestHeader("Connection", "close");
        http.setRequestHeader("Content-type", "application/json;charset=UTF-8");
        http.send(body);

        http.onreadystatechange = function() { // Call a function when the state changes.
            // readyState 4 means that the request finished and response is ready. Even if there
            // are errors along the way, it will get to state 4 anyway.
            console.log("26042020# status :"+http.status +"[Response] :"+ http.responseText);
            if (http.readyState == 4) {
                console.log("status: " + http.status + " url: " + url);
                var response = "";
                var ret_status = http.status;
            }
        }
    }

    function processPost(status, response, reqUrl){
        console.log("QML Log :: VgwPageManager :: ====pagemanager processPost 1 "+response.target)

    }
}

