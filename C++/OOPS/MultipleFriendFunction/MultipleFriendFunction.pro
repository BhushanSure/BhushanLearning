TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        humidity.cpp \
        main.cpp \
        temperature.cpp

HEADERS += \
    humidity.h \
    temperature.h
