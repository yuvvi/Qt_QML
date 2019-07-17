# QML singleton

1. In Color_Comp.qml
  - "pragma singleton" line need to be added
  - Define properties to be used.
2. In qmldir
  - singleton CompColor 1.0 Color_Comp.qml
3. In main.qml
  - import CompColor 1.0
