QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = units
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS
TEMPLATE = app
VERSION = 2.0

SOURCES += \
    distancewidget.cpp \
    main.cpp \
    mainwindow.cpp \
    speed.cpp \
    temperaturewidget.cpp \
    weightwidget.cpp

HEADERS += \
    distancewidget.h \
    global.h \
    mainwindow.h \
    speed.h \
    temperaturewidget.h \
    weightwidget.h

FORMS += \
    distancewidget.ui \
    mainwindow.ui \
    speed.ui \
    temperaturewidget.ui \
    weightwidget.ui

unix:!android {
    target.path = $${PREFIX}/bin
    icon.path = /usr/share/pixmaps
    icon.files = icons/equals.png
    desktop.path = /usr/share/applications
    desktop.files = units.desktop
    INSTALLS += target icon desktop
}

win32 {
    VERSION = $${VERSION}.0.0
    QMAKE_TARGET_COMPANY = DP Software
    QMAKE_TARGET_DESCRIPTION = A simple unit converter between metric and imperial systems
    QMAKE_TARGET_COPYRIGHT = \\251 2020 Dimitris Psathas
    QMAKE_TARGET_PRODUCT = Units
    RC_ICONS = icons/equals.ico
    RC_LANG = 0x408
    RC_CODEPAGE = 1253
}

DISTFILES += \
    icons/equals.ico \
    icons/equals.png \
    units.desktop

RESOURCES += \
    units.qrc
