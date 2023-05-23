#include "frmmain.h"
#include "ui_frmmain.h"
#include <QFileDialog>

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

void FrmMain::on_btn_save_clicked()
{
    getUserInput();
    clearLineEdits();
    saveFileDialog();
}


void FrmMain::on_btn_open_clicked()
{
    // Serialization: Load the data from the file
    openFileDialog();
    outputData();
}


void FrmMain::on_btn_clear_clicked()
{
    ui->tb_output->clear();
}

void FrmMain::getUserInput()
{
    person.firstName = ui->le_firstName->text();
    person.lastName = ui->le_lastName->text();
    person.age = ui->sb_Age->text().toInt();
}

void FrmMain::clearLineEdits()
{
    ui->le_firstName->clear();
    ui->le_lastName->clear();
    ui->sb_Age->clear();
}

void FrmMain::outputData()
{
    ui->tb_output->append("First Name: " + person.firstName);
    ui->tb_output->append("Last Name: " + person.lastName);
    ui->tb_output->append("Age: " + QString::number(person.age));
    ui->tb_output->append("\n--------\n");
}

void FrmMain::saveFileDialog()
{
    // Prompt the user to select a file for saving (only txt files supported)
    fileName = QFileDialog::getSaveFileName(nullptr, "Save File", "", "Text Files (*.txt)");

    if (!fileName.isEmpty())
    {
            // Open the file for writing
            QFile file(fileName);
            // Serialization: Save the data into a file
            if (person.saveToFile(fileName)) ui->tb_output->append("Data was saved into the file\n");
            else ui->tb_output->append("Problem saving data into the file\n");
    }
    else
    {
        ui->tb_output->append("No file Selected");
    }
}

void FrmMain::openFileDialog()
{
    // Open file dialog (only txt files supported)
    fileName = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Text Files (*.txt);");

    // Check if a file was selected
    if (!fileName.isEmpty())
    {
        QFileInfo fileInfo(fileName);
        if (person.loadFromFile(fileName)) ui->tb_output->append("Data was loaded from file\n");
        else ui->tb_output->append("Problem loading data from file\n");
    }
    else
    {
        ui->tb_output->append("No file Selected");
    }
}
