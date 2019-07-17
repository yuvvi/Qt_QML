# Import Qt object, Qt class, signal & slot to QML
## Export class as component
```
         EXPORT CLASS AS COMPONENT
(arg1: import module name.Ex: import ApplnLayer 1.0
 arg2: Major version
 arg3: Minor version
 arg4: component name to be used in QML)
```
 > qmlRegisterType<ApplicationLayer>("ApplnLayer",1,0,"Applyr_comp");

- Functions used in QML need to be given as Q_INVOKABLE
```
Q_INVOKABLE void print_operation();
```
## Export class as Object
```
ApplicationLayer *al_obj = new ApplicationLayer;
engine.rootContext()->setContextProperty("appObj",al_obj);
```
