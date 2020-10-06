#ifndef SCENEDIALOGTITLE_H
#define SCENEDIALOGTITLE_H

#include <QDialog>

namespace Ui {
class SceneDialogTitle;
}
/**
 * @brief 设置窗口标题的弹窗类
 */
class SceneDialogTitle : public QDialog
{
    Q_OBJECT

public:
    explicit SceneDialogTitle(QWidget *parent = nullptr);
    ~SceneDialogTitle();

private:
    Ui::SceneDialogTitle *ui;
};

#endif // SCENEDIALOGTITLE_H
