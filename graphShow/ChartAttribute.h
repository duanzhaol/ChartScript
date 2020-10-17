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
    /**
    * @brief 窗口构造函数，在这里设定了combox的选项
    * @param parent
    */
   ChartAttribute(QWidget *parent = nullptr);

    ~ChartAttribute();
   /**
     * @brief getUi
     * 获得ui的引用
     * @return ui*
     */
    Ui::ChartAttribute* getUi();

	QString getSelectColor()const;
	QString getZoomColor()const;

signals:
	void confirm();

private:
    Ui::ChartAttribute *ui;
    //MyChartItem *myItem;
};

#endif // CHARTATTRIBUTE_H
