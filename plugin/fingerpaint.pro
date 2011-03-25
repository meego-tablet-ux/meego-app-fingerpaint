TEMPLATE = app
TARGET  = fingerpaint
QT += declarative opengl network
CONFIG += qt plugin meegotouch

# Input
SOURCES += \
    app.cpp \
    main.cpp \
    mainwindow.cpp \
    fingerpaint.cpp

HEADERS += \
    app.h \
    windowinfo.h \
    mainwindow.h \
    Fingerpaint.h

OBJECTS_DIR = .obj
MOC_DIR = .moc

target.files += $$TARGET
target.path += $$INSTALL_ROOT/usr/bin

qmlfiles.files += *.qml images/
qmlfiles.path += $$INSTALL_ROOT/usr/share/$$TARGET

INSTALLS += target qmlfiles

OTHER_FILES += \
    fingerpaint.qml \
    main.qml
