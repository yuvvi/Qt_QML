# Import Qt object, Qt class, signal & slot to QML
## Export class as component
'''
------------------------------------------------------
         EXPORT CLASS AS COMPONENT
-----------------------------------------------------
(arg1: import module name.Ex: import ApplnLayer 1.0
 arg2: Major version
 arg3: Minor version
 arg4: component name to be used in QML)
 '''
 > qmlRegisterType<ApplicationLayer>("ApplnLayer",1,0,"Applyr_comp");
