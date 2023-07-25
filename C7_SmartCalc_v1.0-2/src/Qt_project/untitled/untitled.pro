QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Вы можете заставить ваш код не компилироваться, если он использует устаревшие API.
# Чтобы сделать это, раскомментируйте следующую строку.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # отключает все API, устаревшие до Qt 6.0.0

SOURCES += \
    ../../s21_calc.c \
    graphwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../../s21_calc.h \
    graphwindow.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    graphwindow.ui \
    mainwindow.ui

# Правила развертывания по умолчанию.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
