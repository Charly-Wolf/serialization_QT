#include "frmmain.h"
#include "ui_frmmain.h"

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
    QString fileName = "person.txt";

    person.firstName = ui->le_firstName->text();
    person.lastName = ui->le_lastName->text();
    person.age = ui->sb_Age->text().toInt();

    // Serialization: Save the data into a file in the build folder of this project
    if (person.saveToFile(fileName)) ui->tb_output->append("Data was saved into the file");

    // Serialization: Load the data from the file
    if (person.loadFromFile(fileName)) ui->tb_output->append("Data was loaded from the file\n");

    ui->tb_output->append("First Name: " + person.firstName);
    ui->tb_output->append("Last Name: " + person.lastName);
    ui->tb_output->append("Age: " + QString::number(person.age));
    ui->tb_output->append("--------\n");
}

