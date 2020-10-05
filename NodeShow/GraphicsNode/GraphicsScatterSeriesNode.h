#ifndef GRAPHICSSCATTERSERIESNODE_H
#define GRAPHICSSCATTERSERIESNODE_H

#include <QWidget>

namespace Ui {
class GraphicsScatterSeriesNode;
}

class GraphicsScatterSeriesNode : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsScatterSeriesNode(QWidget *parent = nullptr);
    ~GraphicsScatterSeriesNode();

private:
    Ui::GraphicsScatterSeriesNode *ui;
};

#endif // GRAPHICSSCATTERSERIESNODE_H
