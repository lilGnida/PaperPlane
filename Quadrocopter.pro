QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataBase/databaseconnector.cpp \
    DataBase/databaseconnectorcontroller.cpp \
    DataBase/databasemanager.cpp \
    Map/controller.cpp \
    Map/dbmanager.cpp \
    Map/mapWorker.cpp \
    Map/maplayer.cpp \
    Map/maptile.cpp \
    Map/mapviewcontroller.cpp \
    Map/scenecontroller.cpp \
    PlaneProcessor/plane.cpp \
    PlaneProcessor/planegraphicsobject.cpp \
    PlaneProcessor/planeprocessor.cpp \
    WorkFromFolder/folderconnection.cpp \
    WorkFromFolder/folderconnectioncontroller.cpp \
    WorkFromFolder/folderworker.cpp \
    main.cpp \
    mainwindow.cpp \
    network/connectionmanagement.cpp \
    network/networkcontroller.cpp \
    network/networklineedit.cpp \
    network/newudpconnection.cpp

HEADERS += \
    DataBase/databaseconnector.h \
    DataBase/databaseconnectorcontroller.h \
    DataBase/databasemanager.h \
    Map/controller.h \
    Map/dbmanager.h \
    Map/mapWorker.h \
    Map/maplayer.h \
    Map/maptile.h \
    Map/mapviewcontroller.h \
    Map/scenecontroller.h \
    PlaneProcessor/plane.h \
    PlaneProcessor/planegraphicsobject.h \
    PlaneProcessor/planeprocessor.h \
    WorkFromFolder/folderconnection.h \
    WorkFromFolder/folderconnectioncontroller.h \
    WorkFromFolder/folderworker.h \
    mainwindow.h \
    network/connectionmanagement.h \
    network/networkcontroller.h \
    network/networklineedit.h \
    network/newudpconnection.h

FORMS += \
    DataBase/databaseconnector.ui \
    WorkFromFolder/folderconnection.ui \
    mainwindow.ui \
    network/connectionmanagement.ui \
    network/newudpconnection.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
