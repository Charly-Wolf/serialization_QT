#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FrmMain; }
QT_END_NAMESPACE

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private slots:
    void on_btn_debug_clicked();

private:
    Ui::FrmMain *ui;
    Person person;
};
#endif // FRMMAIN_H
