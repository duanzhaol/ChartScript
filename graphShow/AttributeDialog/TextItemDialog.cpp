#include "TextItemDialog.h"
#include "ui_TextItemDialog.h"
#include "TextEdit.h"

TextItemDialog::TextItemDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TextItemDialog)
{
	ui->setupUi(this);
	ui->tabWidget->insertTab(0,textEdit,QStringLiteral("文本编辑"));
}

TextItemDialog::~TextItemDialog()
{
	delete ui;
}

QTextDocument *TextItemDialog::getDocument()
{
	return textEdit->getDocument();
}

void TextItemDialog::setDocument(QTextDocument *dcument)
{
	 textEdit->setDocument(dcument);
}
