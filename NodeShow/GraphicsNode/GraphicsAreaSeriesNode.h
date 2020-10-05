#ifndef GRAPHICSAREASERIESNODE_H
#define GRAPHICSAREASERIESNODE_H

#include <QWidget>

namespace Ui {
class GraphicsAreaSeriesNode;
}

class GraphicsAreaSeriesNode : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsAreaSeriesNode(QWidget *parent = nullptr);
    ~GraphicsAreaSeriesNode();

private:
    Ui::GraphicsAreaSeriesNode *ui;
};

#endif // GRAPHICSAREASERIESNODE_H
