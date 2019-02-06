QT += widgets testlib

SOURCES = \
    complib.cpp \
    test.cpp

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

# install
target.path = /tmp/$${TARGET}/bin
INSTALLS += target

HEADERS += \
    complib.h
