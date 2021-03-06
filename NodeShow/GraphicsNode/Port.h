#ifndef PORT_H
#define PORT_H

#include <QWidget>

namespace Ui {
class Port;
}
/**
 * @brief
 * 单个端口
 */

class Port : public QWidget
{
    Q_OBJECT

public:
    explicit Port(QWidget *parent = nullptr);
    ~Port();

private:
    Ui::Port *ui;
};

#endif // PORT_H
