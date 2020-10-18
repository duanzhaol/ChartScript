#ifndef TEXTITEMDIALOG_H
#define TEXTITEMDIALOG_H

#include <QDialog>
#include <QTextDocument>
#include "TextEdit.h"

namespace Ui {
class TextItemDialog;
}

class TextItemDialog : public QDialog
{
	Q_OBJECT

	TextEdit*textEdit = new TextEdit(this);

public:
	explicit TextItemDialog(QWidget *parent = nullptr);
	~TextItemDialog();
	QTextDocument*getDocument();
	void setDocument(QTextDocument*dcument);

private:
	Ui::TextItemDialog *ui;
};

#endif // TEXTITEMDIALOG_H
