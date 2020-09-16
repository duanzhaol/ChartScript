#ifndef GRAPHICSSTARTNODE_H
#define GRAPHICSSTARTNODE_H

#include <QWidget>

namespace Ui {
class GraphicsStartNode;
}

class GraphicsStartNode : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsStartNode(QWidget *parent = nullptr);
    ~GraphicsStartNode();

private:
    Ui::GraphicsStartNode *ui;
};

#endif // GRAPHICSSTARTNODE_H
