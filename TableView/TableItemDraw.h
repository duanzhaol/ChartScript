#ifndef TABLEITEMDRAW_H
#define TABLEITEMDRAW_H

#include <QStyledItemDelegate>
#include <QIcon>
#include <QObject>

class TableItemDraw : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit TableItemDraw(QObject *parent = nullptr);

signals:

public slots:


private:

    QString font = "Big Calson";

    //绘图
    virtual void paint(QPainter* painter,const QStyleOptionViewItem& option,const QModelIndex& index) const;

    //单元格推荐大小
    virtual QSize sizeHint(const QStyleOptionViewItem& option,const QModelIndex& index) const;

private:
    QPixmap iconPie, iconHis;
};

#endif // TABLEITEMDRAW_H
