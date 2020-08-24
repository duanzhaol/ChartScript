#ifndef MULTIMIMEDATA_H
#define MULTIMIMEDATA_H
#include<QMimeData>
#include "ChartItem.h"
/**
 * @brief 复制/剪切时的缓存
 * @bug 需要解决拷贝函数的问题，否则无法实现
 */
class MultiMimeData : public QMimeData
{
    Q_OBJECT
public:
    MultiMimeData(QList<ChartItem*> items);
    ~MultiMimeData();
    QList<ChartItem *> items() const;
private:
    QList<ChartItem *> m_items;
};

#endif // MULTIMIMEDATA_H
