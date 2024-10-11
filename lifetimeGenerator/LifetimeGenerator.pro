QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# Für MSVC
win32-msvc* {
    QMAKE_CXXFLAGS += /W4
}
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cubicspline.cpp \
    data_loader.cpp \
    distribution_creater.cpp \
    dltpulsegenerator.cpp \
    dpulsestreamapi.cpp \
    main.cpp \
    mainwindowpulsegenerator.cpp \
    random_generator.cpp \
    startwindow.cpp \
    mainwindow.cpp \
    spectragenerator.cpp \   
    window1.cpp

HEADERS += \
    cubicspline.h \
    data_loader.h \
    distribution_creater.h \
    dltpulsegenerator.h \
    dpulsestreamapi.h \
    mainwindowpulsegenerator.h \
    random_generator.h \
    startwindow.h \
    mainwindow.h \
    spectragenerator.h \  
    window1.h

FORMS += \
    mainwindowpulsegenerator.ui \
    startwindow.ui \
    mainwindow.ui \
    window1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Bilder.qrc

DISTFILES +=
