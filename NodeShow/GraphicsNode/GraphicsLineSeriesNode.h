#ifndef GRAPHICSLINESERIESNODE_H
#define GRAPHICSLINESERIESNODE_H

#include <QWidget>

namespace Ui {
class GraphicsLineSeriesNode;
}

class GraphicsLineSeriesNode : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsLineSeriesNode(QWidget *parent = nullptr);
    ~GraphicsLineSeriesNode();

private:
    Ui::GraphicsLineSeriesNode *ui;
};

#endif // GRAPHICSLINESERIESNODE_H
