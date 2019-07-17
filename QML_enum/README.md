Enumerations cannot be created in QML upto Qt5.5.
Here there is implementation to export enums from Qt to QML
1. In mycolor.h \n "enum Color{}" should be in public section.
   Enum should be registered via Q_ENUMS(Color)
   1.3. As mycolor class instance is not required, constructor should be private section.
   1.4. Create a static function to cal registrations "qRegisterMetaType & qmlRegisterUncreatableType"
2. In myColor.cpp
   2.1. qRegisterMetaType<MyColor::Color>("MyColorQML::Color");
   2.2 qmlRegisterUncreatableType<MyColor>("MyColorQMLModule",1,0,"MyColors","Instance not required");

3. In main.qml
   3.1. import MyColorQMLModule 1.0
   3.2. use as MyColors.RED
 
  
