#ifndef SCENEDIALOGTHEME_H
#define SCENEDIALOGTHEME_H

#include <QDialog>

namespace Ui {
class sceneDialogTheme;
}

class SceneDialogTheme : public QDialog
{
    Q_OBJECT

public:
    explicit SceneDialogTheme(QWidget *parent = nullptr);
    ~SceneDialogTheme();

private:
    Ui::sceneDialogTheme *ui;
};

#endif // SCENEDIALOGTHEME_H
