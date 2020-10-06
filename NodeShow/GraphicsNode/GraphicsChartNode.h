#ifndef GRAPHICSCHARTNODE_H
#define GRAPHICSCHARTNODE_H

#include <QWidget>

namespace Ui {
class GraphicsChartNode;
}

class GraphicsChartNode : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsChartNode(QWidget *parent = nullptr);
    ~GraphicsChartNode();

private:
    Ui::GraphicsChartNode *ui;
};

#endif // GRAPHICSCHARTNODE_H
