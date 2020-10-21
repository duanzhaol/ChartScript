#include "Setting.h"
#include "ui_Setting.h"

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);

    translator = new QTranslator();

    isCN = true;
}

Setting::~Setting()
{
    delete ui;
}

void Setting::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        if(ui->comboBox->currentIndex() == 0 && !isCN)
        {
            ui->comboBox->setCurrentIndex(1);
        }
        break;
    default:
        break;
    }
}

void Setting::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        translator->load(":/new/prefix1/Translate_CN.qm");
        isCN = true;
        break;
    case 1:
        translator->load(":/new/prefix1/Translate_EN.qm");
        isCN = false;
        break;
    default:
        break;
    }

    qApp->installTranslator(translator);

    ui->retranslateUi(this);
}
