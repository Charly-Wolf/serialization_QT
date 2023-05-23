#include "frmmain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FrmMain w;
    w.show();
    w.setWindowTitle("Serialization in QT"); // Custom title
    return a.exec();
}
