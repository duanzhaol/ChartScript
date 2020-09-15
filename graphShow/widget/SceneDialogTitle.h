#ifndef SCENEDIALOGTITLE_H
#define SCENEDIALOGTITLE_H

#include <QDialog>

namespace Ui {
class SceneDialogTitle;
}

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
