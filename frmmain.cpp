#include "frmmain.h"
#include "ui_frmmain.h"
#include <QFileDialog>

FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmMain)
{
    ui->setupUi(this);

    fillLocationsList();
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
    if (openFileDialog())
        outputData();
}

void FrmMain::on_btn_clear_clicked()
{
    ui->tb_output->clear();
}

// ----Helper Functions----
void FrmMain::getUserInput()
{
    person.setFirstName(ui->le_firstName->text()); // TO DO: Use Regex to validate first name
    person.setLastName(ui->le_lastName->text()); // TO DO:  Use Regex to validate last name
    person.setAge(ui->sb_Age->text().toInt()); // TO DO: validate age, between 0 and 150
    person.location.setLocationName(ui->cb_location->currentText());
}

void FrmMain::clearInputFields()
{
    ui->le_firstName->clear();
    ui->le_lastName->clear();
    ui->sb_Age->clear();
    ui->cb_location->setCurrentIndex(0);
}

void FrmMain::outputData()
{
    ui->tb_output->append("First Name: " + person.getFirstName()); // TO DO: use getter
    ui->tb_output->append("Last Name: " + person.getLastName()); // TO DO: use getter
    ui->tb_output->append("Age: " + QString::number(person.getAge())); // TO DO: use getter
    ui->tb_output->append("Location: " + person.location.getLocationName());
    ui->tb_output->append("\n--------\n");
}

void FrmMain::saveFileDialog()
{
    // Prompt the user to select a file for saving (only txt files supported)
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save File", "", "Text Files (*.txt)");
    // Check if a file was selected
    if (!filePath.isEmpty())
    {
            // Open the file for writing
            QFile file(filePath);
            // Serialization: Save the data into a file
            if (person.saveToFile(filePath))
            {
                ui->tb_output->append("Data was saved into " + getFileName(filePath) + "\n--------\n");
                clearInputFields();
            }

            else ui->tb_output->append("Problem saving data into the file\n");
    }
    else
    {
        ui->tb_output->append("No file Selected");
    }
}

bool FrmMain::openFileDialog()
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
            setLineEdits(person.getFirstName(), person.getLastName(), person.getAge(), person.getLocation()); // TO DO: use getters
            return true;
        }
        else ui->tb_output->append("Problem loading data from file\n");
    }
    else
    {
        ui->tb_output->append("No file Selected");
    }
    return false;
}

QString FrmMain::getFileName(const QString& filePath)
{
    QFileInfo fileInfo(filePath);
    return fileInfo.fileName();
}

void FrmMain::setLineEdits(const QString& firstName, const QString& lastName, int age, Location location)
{
    ui->le_firstName->setText(firstName);
    ui->le_lastName->setText(lastName);
    ui->sb_Age->setValue(age);
    ui->cb_location->setCurrentText(location.getLocationName());

}

void FrmMain::fillLocationsList()
{
    locations.clear();
    locations << Location("Frankfurt am Main") << Location("Darmstadt") << Location("Hofheim") << Location("Berlin");
    sortLocations();
    for(Location city : locations)
    {
        ui->cb_location->addItem(city.getLocationName());
    }
}

void FrmMain::sortLocations()
{
    std::sort(
                locations.begin(),
                locations.end(),
                // Lambda function
                [](Location loc1, Location loc2)
                {
                    return loc1.getLocationName().toLower() < loc2.getLocationName().toLower();
                }
    );
}
