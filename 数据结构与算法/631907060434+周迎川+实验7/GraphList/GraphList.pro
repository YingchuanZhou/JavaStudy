TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    graphlist.cpp \
    minspantree.cpp \
    queue.cpp \
    minheap.cpp

HEADERS += \
    graphlist.h \
    minspantree.h \
    queue.h \
    minheap.h \
    ufsets.h
