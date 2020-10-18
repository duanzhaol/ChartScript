SOURCES += \
	$$PWD/AttributeDialog/TextEdit.cpp \
	$$PWD/AttributeDialog/TextItemDialog.cpp \
	$$PWD/GraphShowInitializer.cpp \
    $$PWD/GraphicsView.cpp \
    $$PWD/ListWidget/ListWidget.cpp \
    $$PWD/ListWidget/ListWidgetItem.cpp \
	$$PWD/item/AbstractGraphicsItem.cpp \
    $$PWD/item/GraphicsEllipseItem.cpp \
    $$PWD/item/GraphicsRectItem.cpp \
	$$PWD/item/GraphicsTextItem.cpp \
    $$PWD/item/Select.cpp \
    $$PWD/item/SelectInterface.cpp \
    $$PWD/mywindow.cpp \
    $$PWD/qchartviewfactory.cpp \
    $$PWD/widget/SceneDialogTitle.cpp \
    $$PWD/widget/sceneDialogTheme.cpp \
	graphShow/ChartItem.cpp \
	graphShow/GraphicsScene.cpp \
	graphShow/chartattribute.cpp \


HEADERS += \
	$$PWD/AttributeDialog/TextEdit.h \
	$$PWD/AttributeDialog/TextItemDialog.h \
	$$PWD/GraphShowInitializer.h \
    $$PWD/GraphicsView.h \
    $$PWD/ListWidget/ListWidget.h \
    $$PWD/ListWidget/ListWidgetItem.h \
	$$PWD/item/AbstractGraphicsItem.h \
    $$PWD/item/GraphicsEllipseItem.h \
    $$PWD/item/GraphicsRectItem.h \
	$$PWD/item/GraphicsShapeDefine.h \
	$$PWD/item/GraphicsTextItem.h \
    $$PWD/item/Select.h \
    $$PWD/item/SelectInterface.h \
	$$PWD/mywindow.h \
	$$PWD/qchartviewfactory.h \
	$$PWD/widget/SceneDialogTitle.h \
	$$PWD/widget/sceneDialogTheme.h \
	graphShow/ChartAttribute.h \
	graphShow/ChartItem.h \
        graphShow/GraphicsScene.h

FORMS += \
	$$PWD/AttributeDialog/TextItemDialog.ui \
	$$PWD/mywindow.ui \
	$$PWD/widget/SceneDialogTitle.ui \
	$$PWD/widget/scenedialogtheme.ui \
	graphShow/chartattribute.ui

DISTFILES +=

RESOURCES += \
	$$PWD/resource.qrc
