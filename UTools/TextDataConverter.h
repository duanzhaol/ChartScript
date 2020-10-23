#ifndef TEXTDATACONVERTER_H
#define TEXTDATACONVERTER_H

#include <QVariant>

/**
 * @brief
 * 用于将数据类型由文本转为QVariant
 * @example
 * @code
 * QVariant v(QVariant::String);
 * v.setValue("100");
 * qDebug()<<TextDataConverter::textToVariant(type,new bool,QVariant::Int);
 * @endcode
 * 上述代码将输出100，类型为int
 */

class TextDataConverter
{
public:
	TextDataConverter();
	/**
	 * @brief textToVariant
	 * @param text 待转换文本
	 * @param ok 是否转换成功
	 * @param type 转换成的类型
	 * @return 返回转换结果
	 */
	static QVariant textToVariant(const QString&text,bool*ok,const QVariant::Type type);
};

#endif // TEXTDATACONVERTER_H
