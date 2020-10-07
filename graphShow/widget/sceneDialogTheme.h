#ifndef SCENEDIALOGTHEME_H
#define SCENEDIALOGTHEME_H

#include <QDialog>

namespace Ui {
class sceneDialogTheme;
}
/**
 * @brief 设置主题的弹出窗口类
 */
class SceneDialogTheme : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数，在这里设置了combobox的参数和lable
     * @param parent
     */
    explicit SceneDialogTheme(QWidget *parent = nullptr);
    ~SceneDialogTheme();

private slots:
    /**
     * @brief 点击确定后发出主题改变的信号
     */
    void on_buttonBox_accepted();

private:
    Ui::sceneDialogTheme *ui;
signals:
    /**
     * @brief 主题改变的信号
     * @param 选项，为了方便槽函数的编写，传入index而非text
     */
    void ThemeChange(int type);
};

#endif // SCENEDIALOGTHEME_H
