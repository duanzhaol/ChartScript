#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include<QGraphicsScene>
#include "ChartItem.h"

/**
 * @brief
 * 自定义的场景类，继承自QGraphicsScene
 * 实现了删除，全选，多选，框选等功能
 * @todo 复制，剪切功能（需要解决拷贝的问题)
 */
class GraphicsScene: public QGraphicsScene
{
public:
    /**
     * @brief 构造函数
     * @param parent
     */
    explicit GraphicsScene(QObject *parent = 0);

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
private:
    /**
     * @brief 存储已选中item的列表
     * @bug 1.框选的不会加入列表2.单选的不会加入列表（这个很好解决，但是1不解决的情况下这个列表没法用）（
     * 目前可以用selectedItems()代替
     */
    QList<ChartItem*> selectItems;
public slots:
    /**
     * @brief 槽函数，删除所有选中的item
     */
    void deleteSelect();
    /**
     * @brief 槽函数，选择所有item
     */
    void selectAll();
    /**
     * @brief 主题改变的槽函数，只改变该scene中已经选中的item
     * @param 目标主题的索引
     */
    void ThemeChanged(int type);
};

#endif // GRAPHICSSCENE_H
