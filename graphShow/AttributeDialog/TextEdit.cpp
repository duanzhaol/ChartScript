/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QFontComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QMenu>
#include <QMenuBar>
#include <QTextCodec>
#include <QTextEdit>
#include <QStatusBar>
#include <QToolBar>
#include <QTextCursor>
#include <QTextDocumentWriter>
#include <QTextList>
#include <QtDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMimeData>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#include <QPrinter>
#if QT_CONFIG(printpreviewdialog)
#include <QPrintPreviewDialog>
#endif
#endif
#endif

#include "textedit.h"

#ifdef Q_OS_MAC
const QString rsrcPath = ":/images/mac";
#else
const QString rsrcPath = ":/GraphShowImage/image";
#endif

TextEdit::TextEdit(QWidget *parent)
	: QMainWindow(parent)
{
#ifdef Q_OS_OSX
	setUnifiedTitleAndToolBarOnMac(true);
#endif
	setWindowTitle(QCoreApplication::applicationName());

	textEdit = new QTextEdit(this);
	connect(textEdit, &QTextEdit::currentCharFormatChanged,
			this, &TextEdit::currentCharFormatChanged);
	connect(textEdit, &QTextEdit::cursorPositionChanged,
			this, &TextEdit::cursorPositionChanged);
	setCentralWidget(textEdit);

	setToolButtonStyle(Qt::ToolButtonFollowStyle);
	setupFileActions();
	setupEditActions();
	setupTextActions();

	QFont textFont("Helvetica");
	textFont.setStyleHint(QFont::SansSerif);
	textEdit->setFont(textFont);
	fontChanged(textEdit->font());
	colorChanged(textEdit->textColor());
	alignmentChanged(textEdit->alignment());

	connect(textEdit->document(), &QTextDocument::modificationChanged,
			this, &QWidget::setWindowModified);
	connect(textEdit->document(), &QTextDocument::undoAvailable,
			actionUndo, &QAction::setEnabled);
	connect(textEdit->document(), &QTextDocument::redoAvailable,
			actionRedo, &QAction::setEnabled);

	setWindowModified(textEdit->document()->isModified());
	actionUndo->setEnabled(textEdit->document()->isUndoAvailable());
	actionRedo->setEnabled(textEdit->document()->isRedoAvailable());

#ifndef QT_NO_CLIPBOARD
	actionCut->setEnabled(false);
	connect(textEdit, &QTextEdit::copyAvailable, actionCut, &QAction::setEnabled);
	actionCopy->setEnabled(false);
	connect(textEdit, &QTextEdit::copyAvailable, actionCopy, &QAction::setEnabled);

	connect(QApplication::clipboard(), &QClipboard::dataChanged, this, &TextEdit::clipboardDataChanged);
#endif

	textEdit->setFocus();
	setCurrentFileName(QString());

#ifdef Q_OS_MACOS
	// Use dark text on light background on macOS, also in dark mode.
	QPalette pal = textEdit->palette();
	pal.setColor(QPalette::Base, QColor(Qt::white));
	pal.setColor(QPalette::Text, QColor(Qt::black));
	textEdit->setPalette(pal);
#endif
}

void TextEdit::setupFileActions()
{

}

void TextEdit::setupEditActions()
{
	QToolBar *tb = addToolBar(tr("Edit Actions"));
	QMenu *menu = menuBar()->addMenu(tr("&Edit"));

	const QIcon undoIcon = QIcon::fromTheme("edit-undo", QIcon(rsrcPath + "/editundo.png"));
	actionUndo = menu->addAction(undoIcon, tr("&Undo"), textEdit, &QTextEdit::undo);
	actionUndo->setShortcut(QKeySequence::Undo);
	tb->addAction(actionUndo);

	const QIcon redoIcon = QIcon::fromTheme("edit-redo", QIcon(rsrcPath + "/editredo.png"));
	actionRedo = menu->addAction(redoIcon, tr("&Redo"), textEdit, &QTextEdit::redo);
	actionRedo->setPriority(QAction::LowPriority);
	actionRedo->setShortcut(QKeySequence::Redo);
	tb->addAction(actionRedo);
	menu->addSeparator();

#ifndef QT_NO_CLIPBOARD
	const QIcon cutIcon = QIcon::fromTheme("edit-cut", QIcon(rsrcPath + "/editcut.png"));
	actionCut = menu->addAction(cutIcon, tr("Cu&t"), textEdit, &QTextEdit::cut);
	actionCut->setPriority(QAction::LowPriority);
	actionCut->setShortcut(QKeySequence::Cut);
	tb->addAction(actionCut);

	const QIcon copyIcon = QIcon::fromTheme("edit-copy", QIcon(rsrcPath + "/editcopy.png"));
	actionCopy = menu->addAction(copyIcon, tr("&Copy"), textEdit, &QTextEdit::copy);
	actionCopy->setPriority(QAction::LowPriority);
	actionCopy->setShortcut(QKeySequence::Copy);
	tb->addAction(actionCopy);

	const QIcon pasteIcon = QIcon::fromTheme("edit-paste", QIcon(rsrcPath + "/editpaste.png"));
	actionPaste = menu->addAction(pasteIcon, tr("&Paste"), textEdit, &QTextEdit::paste);
	actionPaste->setPriority(QAction::LowPriority);
	actionPaste->setShortcut(QKeySequence::Paste);
	tb->addAction(actionPaste);
	if (const QMimeData *md = QApplication::clipboard()->mimeData())
		actionPaste->setEnabled(md->hasText());
#endif
}

void TextEdit::setupTextActions()
{
	QToolBar *tb = addToolBar(tr("Format Actions"));
	QMenu *menu = menuBar()->addMenu(tr("F&ormat"));

	const QIcon boldIcon = QIcon::fromTheme("format-text-bold", QIcon(rsrcPath + "/textbold.png"));
	actionTextBold = menu->addAction(boldIcon, tr("&Bold"), this, &TextEdit::textBold);
	actionTextBold->setShortcut(Qt::CTRL + Qt::Key_B);
	actionTextBold->setPriority(QAction::LowPriority);
	QFont bold;
	bold.setBold(true);
	actionTextBold->setFont(bold);
	tb->addAction(actionTextBold);
	actionTextBold->setCheckable(true);

	const QIcon italicIcon = QIcon::fromTheme("format-text-italic", QIcon(rsrcPath + "/textitalic.png"));
	actionTextItalic = menu->addAction(italicIcon, tr("&Italic"), this, &TextEdit::textItalic);
	actionTextItalic->setPriority(QAction::LowPriority);
	actionTextItalic->setShortcut(Qt::CTRL + Qt::Key_I);
	QFont italic;
	italic.setItalic(true);
	actionTextItalic->setFont(italic);
	tb->addAction(actionTextItalic);
	actionTextItalic->setCheckable(true);

	const QIcon underlineIcon = QIcon::fromTheme("format-text-underline", QIcon(rsrcPath + "/textunder.png"));
	actionTextUnderline = menu->addAction(underlineIcon, tr("&Underline"), this, &TextEdit::textUnderline);
	actionTextUnderline->setShortcut(Qt::CTRL + Qt::Key_U);
	actionTextUnderline->setPriority(QAction::LowPriority);
	QFont underline;
	underline.setUnderline(true);
	actionTextUnderline->setFont(underline);
	tb->addAction(actionTextUnderline);
	actionTextUnderline->setCheckable(true);

	menu->addSeparator();

	const QIcon leftIcon = QIcon::fromTheme("format-justify-left", QIcon(rsrcPath + "/textleft.png"));
	actionAlignLeft = new QAction(leftIcon, tr("&Left"), this);
	actionAlignLeft->setShortcut(Qt::CTRL + Qt::Key_L);
	actionAlignLeft->setCheckable(true);
	actionAlignLeft->setPriority(QAction::LowPriority);
	const QIcon centerIcon = QIcon::fromTheme("format-justify-center", QIcon(rsrcPath + "/textcenter.png"));
	actionAlignCenter = new QAction(centerIcon, tr("C&enter"), this);
	actionAlignCenter->setShortcut(Qt::CTRL + Qt::Key_E);
	actionAlignCenter->setCheckable(true);
	actionAlignCenter->setPriority(QAction::LowPriority);
	const QIcon rightIcon = QIcon::fromTheme("format-justify-right", QIcon(rsrcPath + "/textright.png"));
	actionAlignRight = new QAction(rightIcon, tr("&Right"), this);
	actionAlignRight->setShortcut(Qt::CTRL + Qt::Key_R);
	actionAlignRight->setCheckable(true);
	actionAlignRight->setPriority(QAction::LowPriority);
	const QIcon fillIcon = QIcon::fromTheme("format-justify-fill", QIcon(rsrcPath + "/textjustify.png"));
	actionAlignJustify = new QAction(fillIcon, tr("&Justify"), this);
	actionAlignJustify->setShortcut(Qt::CTRL + Qt::Key_J);
	actionAlignJustify->setCheckable(true);
	actionAlignJustify->setPriority(QAction::LowPriority);

	// Make sure the alignLeft  is always left of the alignRight
	QActionGroup *alignGroup = new QActionGroup(this);
	connect(alignGroup, &QActionGroup::triggered, this, &TextEdit::textAlign);

	if (QApplication::isLeftToRight()) {
		alignGroup->addAction(actionAlignLeft);
		alignGroup->addAction(actionAlignCenter);
		alignGroup->addAction(actionAlignRight);
	} else {
		alignGroup->addAction(actionAlignRight);
		alignGroup->addAction(actionAlignCenter);
		alignGroup->addAction(actionAlignLeft);
	}
	alignGroup->addAction(actionAlignJustify);

	tb->addActions(alignGroup->actions());
	menu->addActions(alignGroup->actions());

	menu->addSeparator();

	QPixmap pix(16, 16);
	pix.fill(Qt::black);
	actionTextColor = menu->addAction(pix, tr("&Color..."), this, &TextEdit::textColor);
	tb->addAction(actionTextColor);

	tb = addToolBar(tr("Format Actions"));
	tb->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
	addToolBarBreak(Qt::TopToolBarArea);
	addToolBar(tb);

	comboStyle = new QComboBox(tb);
	tb->addWidget(comboStyle);
	comboStyle->addItem("Standard");
	comboStyle->addItem("Bullet List (Disc)");
	comboStyle->addItem("Bullet List (Circle)");
	comboStyle->addItem("Bullet List (Square)");
	comboStyle->addItem("Ordered List (Decimal)");
	comboStyle->addItem("Ordered List (Alpha lower)");
	comboStyle->addItem("Ordered List (Alpha upper)");
	comboStyle->addItem("Ordered List (Roman lower)");
	comboStyle->addItem("Ordered List (Roman upper)");
	comboStyle->addItem("Heading 1");
	comboStyle->addItem("Heading 2");
	comboStyle->addItem("Heading 3");
	comboStyle->addItem("Heading 4");
	comboStyle->addItem("Heading 5");
	comboStyle->addItem("Heading 6");

	connect(comboStyle, QOverload<int>::of(&QComboBox::activated), this, &TextEdit::textStyle);

	comboFont = new QFontComboBox(tb);
	tb->addWidget(comboFont);
	connect(comboFont, QOverload<const QString &>::of(&QComboBox::activated), this, &TextEdit::textFamily);

	comboSize = new QComboBox(tb);
	comboSize->setObjectName("comboSize");
	tb->addWidget(comboSize);
	comboSize->setEditable(true);

	const QList<int> standardSizes = QFontDatabase::standardSizes();
	for (int size : standardSizes)
		comboSize->addItem(QString::number(size));
	comboSize->setCurrentIndex(standardSizes.indexOf(QApplication::font().pointSize()));

	connect(comboSize, QOverload<const QString &>::of(&QComboBox::activated), this, &TextEdit::textSize);
}

void TextEdit::setDocument(QTextDocument *d)
{
	textEdit->setDocument(d);
}

QTextDocument *TextEdit::getDocument()
{
	return textEdit->document();
}


void TextEdit::setCurrentFileName(const QString &fileName)
{
	this->fileName = fileName;
	textEdit->document()->setModified(false);

	QString shownName;
	if (fileName.isEmpty())
		shownName = "untitled.txt";
	else
		shownName = QFileInfo(fileName).fileName();

	setWindowTitle(tr("%1[*] - %2").arg(shownName, QCoreApplication::applicationName()));
	setWindowModified(false);
}



void TextEdit::textBold()
{
	QTextCharFormat fmt;
	fmt.setFontWeight(actionTextBold->isChecked() ? QFont::Bold : QFont::Normal);
	mergeFormatOnWordOrSelection(fmt);
}

void TextEdit::textUnderline()
{
	QTextCharFormat fmt;
	fmt.setFontUnderline(actionTextUnderline->isChecked());
	mergeFormatOnWordOrSelection(fmt);
}

void TextEdit::textItalic()
{
	QTextCharFormat fmt;
	fmt.setFontItalic(actionTextItalic->isChecked());
	mergeFormatOnWordOrSelection(fmt);
}

void TextEdit::textFamily(const QString &f)
{
	QTextCharFormat fmt;
	fmt.setFontFamily(f);
	mergeFormatOnWordOrSelection(fmt);
}

void TextEdit::textSize(const QString &p)
{
	qreal pointSize = p.toFloat();
	if (p.toFloat() > 0) {
		QTextCharFormat fmt;
		fmt.setFontPointSize(pointSize);
		mergeFormatOnWordOrSelection(fmt);
	}
}

void TextEdit::textStyle(int styleIndex)
{
	QTextCursor cursor = textEdit->textCursor();
	QTextListFormat::Style style = QTextListFormat::ListStyleUndefined;

	switch (styleIndex) {
	case 1:
		style = QTextListFormat::ListDisc;
		break;
	case 2:
		style = QTextListFormat::ListCircle;
		break;
	case 3:
		style = QTextListFormat::ListSquare;
		break;
	case 4:
		style = QTextListFormat::ListDecimal;
		break;
	case 5:
		style = QTextListFormat::ListLowerAlpha;
		break;
	case 6:
		style = QTextListFormat::ListUpperAlpha;
		break;
	case 7:
		style = QTextListFormat::ListLowerRoman;
		break;
	case 8:
		style = QTextListFormat::ListUpperRoman;
		break;
	default:
		break;
	}

	cursor.beginEditBlock();

	QTextBlockFormat blockFmt = cursor.blockFormat();

	if (style == QTextListFormat::ListStyleUndefined) {
		blockFmt.setObjectIndex(-1);
		int headingLevel = styleIndex >= 9 ? styleIndex - 9 + 1 : 0; // H1 to H6, or Standard
		blockFmt.setHeadingLevel(headingLevel);
		cursor.setBlockFormat(blockFmt);

		int sizeAdjustment = headingLevel ? 4 - headingLevel : 0; // H1 to H6: +3 to -2
		QTextCharFormat fmt;
		fmt.setFontWeight(headingLevel ? QFont::Bold : QFont::Normal);
		fmt.setProperty(QTextFormat::FontSizeAdjustment, sizeAdjustment);
		cursor.select(QTextCursor::LineUnderCursor);
		cursor.mergeCharFormat(fmt);
		textEdit->mergeCurrentCharFormat(fmt);
	} else {
		QTextListFormat listFmt;
		if (cursor.currentList()) {
			listFmt = cursor.currentList()->format();
		} else {
			listFmt.setIndent(blockFmt.indent() + 1);
			blockFmt.setIndent(0);
			cursor.setBlockFormat(blockFmt);
		}
		listFmt.setStyle(style);
		cursor.createList(listFmt);
	}

	cursor.endEditBlock();
}

void TextEdit::textColor()
{
	QColor col = QColorDialog::getColor(textEdit->textColor(), this);
	if (!col.isValid())
		return;
	QTextCharFormat fmt;
	fmt.setForeground(col);
	mergeFormatOnWordOrSelection(fmt);
	colorChanged(col);
}

void TextEdit::textAlign(QAction *a)
{
	if (a == actionAlignLeft)
		textEdit->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
	else if (a == actionAlignCenter)
		textEdit->setAlignment(Qt::AlignHCenter);
	else if (a == actionAlignRight)
		textEdit->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
	else if (a == actionAlignJustify)
		textEdit->setAlignment(Qt::AlignJustify);
}

void TextEdit::currentCharFormatChanged(const QTextCharFormat &format)
{
	fontChanged(format.font());
	colorChanged(format.foreground().color());
}

void TextEdit::cursorPositionChanged()
{
	alignmentChanged(textEdit->alignment());
	QTextList *list = textEdit->textCursor().currentList();
	if (list) {
		switch (list->format().style()) {
		case QTextListFormat::ListDisc:
			comboStyle->setCurrentIndex(1);
			break;
		case QTextListFormat::ListCircle:
			comboStyle->setCurrentIndex(2);
			break;
		case QTextListFormat::ListSquare:
			comboStyle->setCurrentIndex(3);
			break;
		case QTextListFormat::ListDecimal:
			comboStyle->setCurrentIndex(4);
			break;
		case QTextListFormat::ListLowerAlpha:
			comboStyle->setCurrentIndex(5);
			break;
		case QTextListFormat::ListUpperAlpha:
			comboStyle->setCurrentIndex(6);
			break;
		case QTextListFormat::ListLowerRoman:
			comboStyle->setCurrentIndex(7);
			break;
		case QTextListFormat::ListUpperRoman:
			comboStyle->setCurrentIndex(8);
			break;
		default:
			comboStyle->setCurrentIndex(-1);
			break;
		}
	} else {
		int headingLevel = textEdit->textCursor().blockFormat().headingLevel();
		comboStyle->setCurrentIndex(headingLevel ? headingLevel + 8 : 0);
	}
}

void TextEdit::clipboardDataChanged()
{
#ifndef QT_NO_CLIPBOARD
	if (const QMimeData *md = QApplication::clipboard()->mimeData())
		actionPaste->setEnabled(md->hasText());
#endif
}

void TextEdit::about()
{
	QMessageBox::about(this, tr("About"), tr("This example demonstrates Qt's "
		"rich text editing facilities in action, providing an example "
		"document for you to experiment with."));
}

void TextEdit::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
	QTextCursor cursor = textEdit->textCursor();
	if (!cursor.hasSelection())
		cursor.select(QTextCursor::WordUnderCursor);
	cursor.mergeCharFormat(format);
	textEdit->mergeCurrentCharFormat(format);
}

void TextEdit::fontChanged(const QFont &f)
{
	comboFont->setCurrentIndex(comboFont->findText(QFontInfo(f).family()));
	comboSize->setCurrentIndex(comboSize->findText(QString::number(f.pointSize())));
	actionTextBold->setChecked(f.bold());
	actionTextItalic->setChecked(f.italic());
	actionTextUnderline->setChecked(f.underline());
}

void TextEdit::colorChanged(const QColor &c)
{
	QPixmap pix(16, 16);
	pix.fill(c);
	actionTextColor->setIcon(pix);
}

void TextEdit::alignmentChanged(Qt::Alignment a)
{
	if (a & Qt::AlignLeft)
		actionAlignLeft->setChecked(true);
	else if (a & Qt::AlignHCenter)
		actionAlignCenter->setChecked(true);
	else if (a & Qt::AlignRight)
		actionAlignRight->setChecked(true);
	else if (a & Qt::AlignJustify)
		actionAlignJustify->setChecked(true);
}

