#-------------------------------------------------
#
# Project created by QtCreator 2020-06-13T16:02:00
#
#-------------------------------------------------

QT += quick qml core network
#QT       -= gui
CONFIG += qt c++11
CONFIG += console
#this is required by newer version of clang++ with older version of qt (5.4.1)
QMAKE_CXXFLAGS += -Wno-inconsistent-missing-override
TARGET = lambda_signalSlotTest
CONFIG   -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    lambda.cpp
HEADERS += \
    lambda.h
