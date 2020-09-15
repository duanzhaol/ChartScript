#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include"GraphicsScene.h"
namespace Ui {
class myWindow;
}

class myWindow : public QWidget
{
    Q_OBJECT

public:
    explicit myWindow(QWidget *parent = nullptr);
    void setScene(GraphicsScene *myScene);
    ~myWindow();

private slots:

    void on_pushButton_theme_clicked();

    void on_pushButton_title_clicked();

private:
    Ui::myWindow *ui;
};

#endif // MYWINDOW_H
