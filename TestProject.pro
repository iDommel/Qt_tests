QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Data.cpp \
    main.cpp \
    mainwindow.cpp \
    startScreen/inspectionWidgets/defectinspectionwidget.cpp \
    startScreen/inspectionWidgets/dentinspectionwidget.cpp \
    startScreen/inspectionWidgets/lightninginspectionwidget.cpp \
    startScreen/inspectionWidgets/markinginspectionwidget.cpp \
    startScreen/inspectionWidgets/paintinspectionwidget.cpp \
    startScreen/inspectionwidget.cpp \
    startScreen/mygridwidget.cpp

HEADERS += \
    Data.h \
    mainwindow.h \
    startScreen/inspectionWidgets/defectinspectionwidget.h \
    startScreen/inspectionWidgets/dentinspectionwidget.h \
    startScreen/inspectionWidgets/lightninginspectionwidget.h \
    startScreen/inspectionWidgets/markinginspectionwidget.h \
    startScreen/inspectionWidgets/paintinspectionwidget.h \
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
