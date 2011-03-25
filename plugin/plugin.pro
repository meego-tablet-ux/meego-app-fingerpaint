TEMPLATE = lib
TARGET = Fingerpaint
QT += declarative
CONFIG += qt \
    plugin
TARGET = $$qtLibraryTarget($$TARGET)
DESTDIR = $$TARGET
OBJECTS_DIR = .obj
MOC_DIR = .moc

# Input
SOURCES += components.cpp \
    fingerpaint.cpp
HEADERS += components.h \
    fingerpaint.h

qmldir.files += $$TARGET
qmldir.path += $$[QT_INSTALL_IMPORTS]/MeeGo/App/
INSTALLS += qmldir
