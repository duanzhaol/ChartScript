QT       += axcontainer 

TRANSLATIONS = $$PWD/Translate_EN.ts \
               $$PWD/Translate_CN.ts

SOURCES += \
    $$PWD/DataLoader.cpp \
    $$PWD/MainWidget.cpp \
    $$PWD/Setting.cpp \
    $$PWD/TableModel/TableArrayItem.cpp \
    $$PWD/TableModel/TableWidget.cpp \
    $$PWD/TableViewInitialer.cpp


HEADERS += \
    $$PWD/DataLoader.h \
    $$PWD/GraphicsShowInterface/TableArrayInterface.h \
    $$PWD/MainWidget.h \
    $$PWD/Setting.h \
    $$PWD/TableModel/TableArrayItem.h \
    $$PWD/TableModel/TableWidget.h \
    $$PWD/TableViewInitialer.h

FORMS += \
    $$PWD/ChooseWidget.ui \
    $$PWD/MainWidget.ui \
    $$PWD/Setting.ui \
    $$PWD/StartWidget.ui

RESOURCES += \
    $$PWD/img.qrc \
    $$PWD/translator.qrc
