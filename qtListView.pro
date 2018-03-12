#-------------------------------------------------
#
# Project created by QtCreator 2018-03-12T22:24:41
#
#-------------------------------------------------

QT       -= gui

TEMPLATE = lib
CONFIG += staticlib

TARGET = $$PWD/lib/QtListView

DEFINES += QTLISTVIEW_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

include(qtListView.pri)

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=

HEADERS += \
    BaseListModel.h \
    BaseItemModel.h \
    QtListView.h \
    QtListViewImpl.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    qtListView.pri
