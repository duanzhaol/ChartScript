#ifndef NODESHOWWINDOW_H
#define NODESHOWWINDOW_H

#include <QMainWindow>

namespace Ui {
class NodeShowWindow;
}

class NodeShowWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NodeShowWindow(QWidget *parent = nullptr);
    ~NodeShowWindow();

private:
    Ui::NodeShowWindow *ui;
};

#endif // NODESHOWWINDOW_H
