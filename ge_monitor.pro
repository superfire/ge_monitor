#-------------------------------------------------
#
# Project created by QtCreator 2019-06-02T17:29:34
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ge_monitor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    rt_monitor/monitorwindow.cpp \
    rt_monitor/mytcpclient.cpp \
    mac_scan/arpacceptthread.cpp \
    mac_scan/arpsendthread.cpp \
    mac_scan/updatemacthread.cpp \
    mac_scan/utils.cpp \
    mac_scan/widget.cpp \
    rt_monitor/connect_dialog.cpp

HEADERS += \
        mainwindow.h \
    rt_monitor/monitorwindow.h \
    rt_monitor/mytcpclient.h \
    mac_scan/arpacceptthread.h \
    mac_scan/arpsendthread.h \
    mac_scan/updatemacthread.h \
    mac_scan/utils.h \
    mac_scan/widget.h \
    rt_monitor/connect_dialog.h

FORMS += \
        mainwindow.ui \
    rt_monitor/monitorwindow.ui \
    mac_scan/widget.ui \
    rt_monitor/connect_dialog.ui

INCLUDEPATH += ../ge_monitor/mac_scan

# WpdPack_4_1_2库
LIBS += -lpthread libwsock32 libws2_32 libiphlpapi
# INCLUDEPATH += D:/Lib/WpdPack/Include
# LIBS += D:/Lib/WpdPack/Lib/wpcap.lib
INCLUDEPATH += ../ge_monitor/Lib/WpdPack/Include
LIBS += ../ge_monitor/Lib/WpdPack/Lib/wpcap.lib


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

