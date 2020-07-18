QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTetris
TEMPLATE = app


SOURCES += main.cpp\
    ElectricField.cpp \
    Finish.cpp \
    MagneticField.cpp \
    Point.cpp \
    Proton.cpp \
    Speed.cpp \
    widget.cpp \
    Barrier.cpp \

HEADERS  += widget.h \
    ElectricField.h \
    Finish.h \
    MagneticField.h \
    Point.h \
    Proton.h \
    Speed.h \
    Barrier.h \

FORMS    += widget.ui

NEEDS    += \
    Image\Electric.png

RESOURCES += \
    Image/Image.qrc


