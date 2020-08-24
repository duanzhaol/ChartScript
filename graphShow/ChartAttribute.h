#ifndef CHARTATTRIBUTE_H
#define CHARTATTRIBUTE_H
#include "ChartItem.h"

#include <QDialog>
namespace Ui {
class ChartAttribute;
}
/**
 * @brief 图表的属性窗口类
 */
class ChartAttribute : public QDialog
{
    Q_OBJECT

public:
   ChartAttribute(QWidget *parent = nullptr);

    ~ChartAttribute();
   /**
     * @brief getUi
     * 获得ui的引用
     * @return ui*
     */
    Ui::ChartAttribute* getUi();
public slots:
    /**
     * @brief 点击确定的槽函数
     */
    void on_confirmAttr_clicked();

private:
    Ui::ChartAttribute *ui;
    //MyChartItem *myItem;
};

#endif // CHARTATTRIBUTE_H
