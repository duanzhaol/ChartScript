#ifndef RESIZETEST_H
#define RESIZETEST_H

#include <QWidget>

namespace Ui {
class ResizeTest;
}

class ResizeTest : public QWidget
{
    Q_OBJECT

public:
    explicit ResizeTest(QWidget *parent = nullptr);
    ~ResizeTest();

private:
    Ui::ResizeTest *ui;
};

#endif // RESIZETEST_H
