QT += concurrent widgets printsupport
CONFIG += console

SOURCES += main.cpp \
    printingdemo.cpp \
    mainwindow.cpp

LIBS += -lwinspool

HEADERS += \
    printingdemo.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
