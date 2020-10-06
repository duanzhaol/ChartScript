#ifndef GRAPHICSPIESERIES_H
#define GRAPHICSPIESERIES_H

#include <QWidget>

namespace Ui {
class GraphicsPieSeries;
}

class GraphicsPieSeries : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsPieSeries(QWidget *parent = nullptr);
    ~GraphicsPieSeries();

private:
    Ui::GraphicsPieSeries *ui;
};

#endif // GRAPHICSPIESERIES_H
