#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QTranslator>
#include <QEvent>

namespace Ui {
class Setting;
}
/**
 * @brief
 * 张远写的设置界面，好像没什么用
 */
class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

    void changeEvent(QEvent* e);

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::Setting *ui;

    bool isCN;
    QTranslator* translator;
};

#endif // SETTING_H
