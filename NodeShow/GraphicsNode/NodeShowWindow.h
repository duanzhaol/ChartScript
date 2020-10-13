#ifndef NODESHOWWINDOW_H
#define NODESHOWWINDOW_H

#include "ConnectController.h"

#include <QGraphicsScene>
#include <QMainWindow>

namespace Ui {
class NodeShowWindow;
}

class NodeShowWindow : public QMainWindow
{
    Q_OBJECT
    static NodeShowWindow* instance;

public:
    static NodeShowWindow* getInstance();

    explicit NodeShowWindow(QWidget *parent = nullptr);
    ~NodeShowWindow();
    void drawLine();
    QGraphicsScene* scene = new QGraphicsScene();
    static void createWindow();

private:
    Ui::NodeShowWindow *ui;

};

#endif // NODESHOWWINDOW_H
