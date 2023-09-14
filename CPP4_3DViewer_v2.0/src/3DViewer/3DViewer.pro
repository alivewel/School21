QT       += core gui opengl
mac: QT += openglwidgets
linux: QT += openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Add the INCLUDEPATH directive here
# INCLUDEPATH += $$PWD

SOURCES += \
    ./view/glwidget.cc \
    ./view/viewer.cc \
    ./controller/controller.cc \
    ./model/model.cc \
    ./model/affine_transform.cc \
    ./model/objectinfo.cc \
    ./model/parser.cc \
    ./main.cc \
    ./qtgifimage/src/3rdParty/giflib/dgif_lib.c \
    ./qtgifimage/src/3rdParty/giflib/egif_lib.c \
    ./qtgifimage/src/3rdParty/giflib/gif_err.c \
    ./qtgifimage/src/3rdParty/giflib/gif_font.c \
    ./qtgifimage/src/3rdParty/giflib/gif_hash.c \
    ./qtgifimage/src/3rdParty/giflib/gifalloc.c \
    ./qtgifimage/src/3rdParty/giflib/quantize.c \
    ./qtgifimage/src/gifimage/qgifimage.cpp \

HEADERS += \
    ./view/glwidget.h \
    ./view/viewer.h \
    ./controller/controller.h \
    ./model/model.h \
    ./model/affine_transform.h \
    ./model/objectinfo.h \
    ./model/parser.h \
    ./qtgifimage/src/3rdParty/giflib/gif_hash.h \
    ./qtgifimage/src/3rdParty/giflib/gif_lib.h \
    ./qtgifimage/src/3rdParty/giflib/gif_lib_private.h \
    ./qtgifimage/src/gifimage/qgifglobal.h \
    ./qtgifimage/src/gifimage/qgifimage.h \
    ./qtgifimage/src/gifimage/qgifimage_p.h \

FORMS += \
    ./view/viewer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
