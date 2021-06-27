QT       += core gui
QT += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS   += -lopengl32
LIBS   += -lglu32

TARGET = untitled2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wopengl.cpp

HEADERS  += mainwindow.h \
    wopengl.h

FORMS    += mainwindow.ui
