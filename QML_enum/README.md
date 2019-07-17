Enumerations cannot be created in QML upto Qt5.5.
Here there is implementation to export enums from Qt to QML
1. In mycolor.h
   "enum Color{}" should be in public section.
   Enum should be registered via Q_ENUMS(Color)
   As mycolor class instance is not required, constructor should be private section.
   Create a static function to cal registrations "qRegisterMetaType & qmlRegisterUncreatableType"
2. In myColor.cpp
    qRegisterMetaType<MyColor::Color>("MyColorQML::Color");
    qmlRegisterUncreatableType<MyColor>("MyColorQMLModule",1,0,"MyColors","Instance not required");

3. In main.qml
    import MyColorQMLModule 1.0
    use as MyColors.RED
 
  
