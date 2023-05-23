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

// ----Button Functions----
void FrmMain::on_btn_save_clicked()
{
    getUserInput();
    saveFileDialog();
}

void FrmMain::on_btn_open_clicked()
{
    openFileDialog();
    outputData();
}

void FrmMain::on_btn_clear_clicked()
{
    ui->tb_output->clear();
}


// ----Helper Functions----
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
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save File", "", "Text Files (*.txt)");
    if (!filePath.isEmpty())
    {
            // Open the file for writing
            QFile file(filePath);
            // Serialization: Save the data into a file
            if (person.saveToFile(filePath))
            {
                ui->tb_output->append("Data was saved into " + getFileName(filePath));
                ui->tb_output->append("\n--------\n");
                clearLineEdits();
            }

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
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Text Files (*.txt);");
    // Check if a file was selected
    if (!filePath.isEmpty())
    {
        // Serialization: Load the data from the file
        if (person.loadFromFile(filePath))
        {
            ui->tb_output->append("Data was loaded from " + getFileName(filePath) + "\n");
            setLineEdits(person.firstName, person.lastName, person.age);
        }
        else ui->tb_output->append("Problem loading data from file\n");
    }
    else
    {
        ui->tb_output->append("No file Selected");
    }
}

QString FrmMain::getFileName(const QString& filePath)
{
    QFileInfo fileInfo(filePath);
    return fileInfo.fileName();
}

void FrmMain::setLineEdits(const QString& firstName, const QString& lastName, int age)
{
    ui->le_firstName->setText(firstName); // TO DO: User Regex to validate first name
    ui->le_lastName->setText(lastName); // TO DO: User Regex to validate last name
    ui->sb_Age->setValue(age); // TO DO: validate age, between 0 and 150
}
