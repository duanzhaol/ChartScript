QT       += axcontainer 

TRANSLATIONS = $$PWD/Translate_EN.ts \
               $$PWD/Translate_CN.ts

SOURCES += \
    $$PWD/DataLoader.cpp \
    $$PWD/Setting.cpp \
    $$PWD/TableModel/TableArrayItem.cpp \
    $$PWD/TableModel/TableWidget.cpp \
    $$PWD/TableView.cpp \
    $$PWD/TableViewInitialer.cpp


HEADERS += \
    $$PWD/DataLoader.h \
    $$PWD/GraphicsShowInterface/TableArrayInterface.h \
    $$PWD/Setting.h \
    $$PWD/TableModel/TableArrayItem.h \
    $$PWD/TableModel/TableWidget.h \
    $$PWD/TableView.h \
    $$PWD/TableViewInitialer.h

FORMS += \
    $$PWD/TableView.ui

RESOURCES += \
    $$PWD/img.qrc \
    $$PWD/translator.qrc
