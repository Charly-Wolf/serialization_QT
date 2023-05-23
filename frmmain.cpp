#include "frmmain.h"
#include "ui_frmmain.h"
#include <QDebug>

FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmMain)
{
    ui->setupUi(this);
}

FrmMain::~FrmMain()
{
    delete ui;
}


void FrmMain::on_btn_debug_clicked()
{
    // TEST -> The data will be displayed on the console
    QString fileName = "person.txt";

    person.firstName = ui->le_firstName->text();
    person.lastName = ui->le_lastName->text();
    person.age = ui->sb_Age->text().toInt();

    // Serialization: Save the data into a file in the build folder of this project
    if (person.saveToFile(fileName)) qDebug() << "\nData was saved into the file";

    // Serialization: Load the data from the file
    if (person.loadFromFile(fileName)) qDebug() << "Data was loaded from the file";

    qDebug() << "\nFirst Name:" << person.firstName;
    qDebug() << "Last Name:"<< person.lastName;
    qDebug() << "Alter:" << person.age;
    qDebug() << "--------------";
}

