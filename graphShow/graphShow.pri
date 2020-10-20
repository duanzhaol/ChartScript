SOURCES += \
	$$PWD/AttributeDialog/PixmapItemDialog.cpp \
	$$PWD/AttributeDialog/ShapeItemDialog.cpp \
	$$PWD/AttributeDialog/TextEdit.cpp \
	$$PWD/AttributeDialog/TextItemDialog.cpp \
	$$PWD/GraphShowInitializer.cpp \
    $$PWD/GraphicsView.cpp \
    $$PWD/ListWidget/ListWidget.cpp \
    $$PWD/ListWidget/ListWidgetItem.cpp \
	$$PWD/item/AbstractGraphicsItem.cpp \
	$$PWD/item/GraphicsImageItem.cpp \
	$$PWD/item/GraphicsTextItem.cpp \
    $$PWD/item/Select.cpp \
    $$PWD/item/SelectInterface.cpp \
	$$PWD/item/ShapeItem/AbstractGraphicsShapeItem.cpp \
	$$PWD/item/ShapeItem/GraphicsEllipseItem.cpp \
	$$PWD/item/ShapeItem/GraphicsRectItem.cpp \
	$$PWD/item/ShapeItem/GraphicsTriangleItem.cpp \
    $$PWD/mywindow.cpp \
    $$PWD/qchartviewfactory.cpp \
    $$PWD/widget/SceneDialogTitle.cpp \
    $$PWD/widget/sceneDialogTheme.cpp \
	graphShow/ChartItem.cpp \
	graphShow/GraphicsScene.cpp \
	graphShow/chartattribute.cpp


HEADERS += \
	$$PWD/AttributeDialog/PixmapItemDialog.h \
	$$PWD/AttributeDialog/ShapeItemDialog.h \
	$$PWD/AttributeDialog/TextEdit.h \
	$$PWD/AttributeDialog/TextItemDialog.h \
	$$PWD/GraphShowInitializer.h \
    $$PWD/GraphicsView.h \
    $$PWD/ListWidget/ListWidget.h \
    $$PWD/ListWidget/ListWidgetItem.h \
	$$PWD/item/AbstractGraphicsItem.h \
	$$PWD/item/GraphicsImageItem.h \
	$$PWD/item/GraphicsShapeDefine.h \
	$$PWD/item/GraphicsTextItem.h \
    $$PWD/item/Select.h \
    $$PWD/item/SelectInterface.h \
	$$PWD/item/ShapeItem/AbstractGraphicsShapeItem.h \
	$$PWD/item/ShapeItem/GraphicsEllipseItem.h \
	$$PWD/item/ShapeItem/GraphicsRectItem.h \
	$$PWD/item/ShapeItem/GraphicsTriangleItem.h \
	$$PWD/mywindow.h \
	$$PWD/qchartviewfactory.h \
	$$PWD/widget/SceneDialogTitle.h \
	$$PWD/widget/sceneDialogTheme.h \
	graphShow/ChartAttribute.h \
	graphShow/ChartItem.h \
        graphShow/GraphicsScene.h

FORMS += \
	$$PWD/AttributeDialog/PixmapItemDialog.ui \
	$$PWD/AttributeDialog/ShapeItemDialog.ui \
	$$PWD/AttributeDialog/TextItemDialog.ui \
	$$PWD/mywindow.ui \
	$$PWD/widget/SceneDialogTitle.ui \
	$$PWD/widget/scenedialogtheme.ui \
	graphShow/chartattribute.ui

DISTFILES +=

RESOURCES += \
	$$PWD/GraphShow.qrc
