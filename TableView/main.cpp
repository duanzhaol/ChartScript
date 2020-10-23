#include <MainWidget.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    StartWidget w;
//    w.show();

    MainWidget w;
    w.show();
    QVariant *newType=new QVariant(QString("abc"));
    qDebug()<<newType->typeName();
    return a.exec();
}
