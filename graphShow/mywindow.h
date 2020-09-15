#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include"GraphicsScene.h"
namespace Ui {
class myWindow;
}
/**
 * @brief 主窗口类
 */
class myWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief 平淡无奇的构造函数
     * @param parent
     */
    explicit myWindow(QWidget *parent = nullptr);
    /**
     * @brief 设置当前窗口的Qgraphicsview的scene
     * @param GraphicsScene
     */
    void setScene(GraphicsScene *myScene);
    ~myWindow();

private slots:
    /**
     * @brief 点击主题按钮，弹出主题窗口
     */
    void on_pushButton_theme_clicked();
    /**
     * @brief 点击标题按钮，弹出标题窗口
     */
    void on_pushButton_title_clicked();

private:
    Ui::myWindow *ui;

};

#endif // MYWINDOW_H
