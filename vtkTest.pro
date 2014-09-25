#-------------------------------------------------
#
# Project created by QtCreator 2014-09-18T02:26:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vtkTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\\VTK\\VTK-install\\include\\vtk-5.10

LIBS += -LC:\\VTK\\VTK-install\\lib\\vtk-5.10

LIBS += -lvtkCommon\
-lvtksys\
-lQVTK\
-lvtkViews\
-lvtkWidgets\
-lvtkInfovis\
-lvtkRendering\
-lvtkGraphics\
-lvtkImaging\
-lvtkIO\
-lvtkFiltering\
-lvtklibxml2\
-lvtkDICOMParser\
-lvtkpng\
-lvtkpng\
-lvtktiff\
-lvtkzlib\
-lvtkjpeg\
-lvtkalglib\
-lvtkexpat\
-lvtkverdict\
-lvtkmetaio\
-lvtkNetCDF\
-lvtksqlite\
-lvtkexoIIc\
-lvtkftgl\
-lvtkfreetype\
-lvtkHybrid\
