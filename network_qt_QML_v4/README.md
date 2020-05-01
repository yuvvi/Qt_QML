Network operations from QML to cpp.
QML uses XMLhttpRequest (not recommended to use)
Qt uses NetworkAccessManager.(NAM)
response from NAM is received at QML using either JSON response, QByteArray (after Qt5.8),
