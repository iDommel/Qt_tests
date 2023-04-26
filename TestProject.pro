QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DONECLE_PATH = $$(DONECLE_LIBRARIES)
isEmpty(DONECLE_PATH){
DONECLE_PATH = $${DONECLE_LIBRARIES}
}
isEmpty(DONECLE_PATH){
        exists(C:/Donecle/Libraries) {
                DONECLE_PATH=C:/Donecle/Libraries
        } else {
                error("Cannot find Donecle libraries. Please add the line DONECLE_LIBRARIES=C:/Qt/Libraries (the path to the cloned project commun/Libraries.git) in PATH or in the kit environment.")
        }
}
include($${DONECLE_PATH}/include.pri)
#reload you cunt

SOURCES += \
    Data.cpp \
    data/inspectionsessionmanager.cpp \
    jsondata.cpp \
    main.cpp \
    mainwindow.cpp \
    startScreen/inspectionWidgets/markinginspectionwidget.cpp \
    startScreen/inspectionwidget.cpp \
    startScreen/mygridwidget.cpp

HEADERS += \
    Data.h \
    data/inspectionsessionmanager.h \
    data/softwareconfig.h \
    jsondata.h \
    mainwindow.h \
    startScreen/inspectionWidgets/markinginspectionwidget.h \
    startScreen/inspectionwidget.h \
    startScreen/mygridwidget.h

FORMS += \
    mainwindow.ui \
    startScreen/inspectionWidget.ui \
    startScreen/mygridwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
