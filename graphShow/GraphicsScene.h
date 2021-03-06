#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include<QGraphicsScene>
#include "ChartItem.h"
#include <QListWidgetItem>
#include"item/ShapeItem/GraphicsRectItem.h"
#include"item/ShapeItem/GraphicsEllipseItem.h"
#include <QtCharts/QChart>
#include <optional>
/**
 * @brief
 * 自定义的场景类，继承自QGraphicsScene
 * 实现了删除，全选，多选，框选等功能
 * @todo 复制，剪切功能（需要解决拷贝的问题)
 */
class GraphicsScene: public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     * @param parent
     */
	explicit GraphicsScene(QObject *parent = nullptr);


protected:

	/**
	 * @brief
     * 鼠标点击事件（未被item接收到或点击了空白区域的在这里处理)
     * 如果是左键且按了ctrl，则增加当前item的选中（多选）
     * 如果左击空白区域，则清空选中
     * @param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /**
     * @brief 鼠标移动事件
     * @param event
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    /**
     * @brief G键盘事件，如果按了delete键，则删除所有选中的item
     * @param event
     */
    void keyPressEvent(QKeyEvent *event);

public slots:
    /**
     * @brief 槽函数，删除所有选中的item
     */
    void deleteSelect();
    /**
     * @brief 槽函数，选择所有item
     */
	void selectAll(bool isSelect);
    /**
     * @brief 主题改变的槽函数，只改变该scene中已经选中的item
     * @param 目标主题的索引
     */
    void ThemeChanged(int type);
    void recieveChart(ChartItem *item);
    void recieveGraphics(QListWidgetItem *item);
    void toTop();

signals:
	void mouseMove(const QPointF&);

};

#endif // GRAPHICSSCENE_H
