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

    // Custom Functions
    void getUserInput();
    void clearLineEdits();
    void outputData();

    // Button Funtions
private slots:
    void on_btn_save_clicked();
    void on_btn_open_clicked();
    void on_btn_clear_clicked();

private:
    Ui::FrmMain *ui;
    Person person;
    QString fileName = "person.txt";
};
#endif // FRMMAIN_H
