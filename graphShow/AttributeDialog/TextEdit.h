

#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>
#include <QMap>
#include <QPointer>
#include <QTextDocument>

QT_BEGIN_NAMESPACE
class QAction;
class QComboBox;
class QFontComboBox;
class QTextEdit;
class QTextCharFormat;
class QMenu;
class QPrinter;
QT_END_NAMESPACE

/**
 * @brief
 * copy自Qt示例，用于生成文本框的文字编辑窗口
 * @copyright  Copyright (C) 2016 The Qt Company Ltd.
 * Contact: https://www.qt.io/licensing/
 */

class TextEdit : public QMainWindow
{
	Q_OBJECT

public:
	TextEdit(QWidget *parent = nullptr);

	void setDocument(QTextDocument*);
	QTextDocument*getDocument();

private slots:

	void textBold();
	void textUnderline();
	void textItalic();
	void textFamily(const QString &f);
	void textSize(const QString &p);
	void textStyle(int styleIndex);
	void textColor();
	void textAlign(QAction *a);

	void currentCharFormatChanged(const QTextCharFormat &format);
	void cursorPositionChanged();

	void clipboardDataChanged();
	void about();

private:
	void setupFileActions();
	void setupEditActions();
	void setupTextActions();
	void setCurrentFileName(const QString &fileName);

	void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
	void fontChanged(const QFont &f);
	void colorChanged(const QColor &c);
	void alignmentChanged(Qt::Alignment a);

	QAction *actionTextBold;
	QAction *actionTextUnderline;
	QAction *actionTextItalic;
	QAction *actionTextColor;
	QAction *actionAlignLeft;
	QAction *actionAlignCenter;
	QAction *actionAlignRight;
	QAction *actionAlignJustify;
	QAction *actionUndo;
	QAction *actionRedo;
#ifndef QT_NO_CLIPBOARD
	QAction *actionCut;
	QAction *actionCopy;
	QAction *actionPaste;
#endif

	QComboBox *comboStyle;
	QFontComboBox *comboFont;
	QComboBox *comboSize;

	QToolBar *tb;
	QString fileName;
	QTextEdit *textEdit;
};

#endif // TEXTEDIT_H
