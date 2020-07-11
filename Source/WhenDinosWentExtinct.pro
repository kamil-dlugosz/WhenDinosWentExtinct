QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airdino.cpp \
    alga.cpp \
    anihilation.cpp \
    bush.cpp \
    dino.cpp \
    disaster.cpp \
    drought.cpp \
    entity.cpp \
    gammaray.cpp \
    grass.cpp \
    inferno.cpp \
    landdino.cpp \
    main.cpp \
    mainwindow.cpp \
    meteor.cpp \
    plant.cpp \
    resources.cpp \
    simulation.cpp \
    tree.cpp \
    waterdino.cpp \
    worldmap.cpp

HEADERS += \
    airdino.h \
    alga.h \
    anihilation.h \
    bush.h \
    dino.h \
    disaster.h \
    drought.h \
    entity.h \
    enum-biome.h \
    enum-kind.h \
    gammaray.h \
    grass.h \
    include-disasters.h \
    include-entities.h \
    inferno.h \
    landdino.h \
    mainwindow.h \
    meteor.h \
    plant.h \
    resources.h \
    simulation.h \
    tree.h \
    waterdino.h \
    worldmap.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  ../resources.qrc
