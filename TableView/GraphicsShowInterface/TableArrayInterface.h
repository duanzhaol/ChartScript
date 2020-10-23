#ifndef TABLEARRAYINTERFACE_H
#define TABLEARRAYINTERFACE_H
#include <QVariant>
/**
 * @brief
 * 与NodeShow部分对接的接口类
 * 使得NodeShow可以从TableView获取到一列数据的引用，并可以进行修改
 */
class TableArrayInterface:public QObject{
    Q_OBJECT
public:
    /**
     * @brief getArrayData
     * 获取这一列当前的数据
     * @return
     * 一个list，不包含name和type，即这个list的第一个元素就是一个数据（第三行)
     */
    virtual QVariantList getArrayData() = 0;
    /**
     * @brief getArrayName
     * 获取当前列的名字
     * @return
     */
    virtual QString getArrayName() = 0;
    /**
     * @brief getArrayType
     * 获取当前列的类型（表格中显示的，如果改变了表格的第二行，但没点保存，数据不会发生对应的改变
     * @return
     */
    virtual QVariant::Type getArrayType() = 0;
    /**
     * @brief setArrayType
     * 设置当前列的类型
     * @param newType
     * 新的类型
     */
    virtual void setArrayType(const QVariant::Type newType) = 0;
    /**
     * @brief setArrayName
     * 设置当前列的名字
     * @param newArrayName
     *
     */
    virtual void setArrayName(const QString &newArrayName) = 0;
    /**
     * @brief setArrayData
     * 设置当前列的数据
     * @param newData
     * 一个list
     */
    virtual void setArrayData(const QVariantList&newData) = 0;
signals:
    void arrayTypeChanged();
    void arrayNameChanged();
    void arrayDataChanged();
    void arrayDelete();
};

#endif // TABLEARRAYINTERFACE_H


