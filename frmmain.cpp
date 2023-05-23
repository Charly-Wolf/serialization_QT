#include "frmmain.h"
#include "ui_frmmain.h"
#include <QDebug>

FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmMain)
{
    ui->setupUi(this);

    person.name = "Max Mustermann";
    person.age = 30;

    QString fileName = "person.dat";

    //--------------------------------------------//

    // Serialisierung: Speichern der Daten in einer Datei
    if (person.saveToFile(fileName)) qDebug() << "Daten wurden in Datei gespeichert";

    // Serialisierung: Laden der daten aus der Datei
    if (person.loadFromFile(fileName)) qDebug() << "Daten wurden aus Datei geladen";

    // Anzeige der geladenen Daten
    qDebug() << "Name:" << person.name;
    qDebug() << "Alter:" << person.age;

    //--------------------------------------------//

    // Ändern der Daten
    person.name = "John Doe";
    person.age = 25;

    // Serialisierung: Speichern der geänderten Daten in einer Datei
    if (person.saveToFile(fileName)) qDebug() << "Geänderte Daten wurden in Datei gespeichert";

    // Serialisierung: Laden der geänderten daten aus der Datei
    if (person.loadFromFile(fileName)) qDebug() << "Daten wurden aus Datei geladen";

    // Anzeige der geänderten Daten
    qDebug() << "Name:" << person.name;
    qDebug() << "Alter:" << person.age;

    //--------------------------------------------//

    // Ändern der Daten
    person.name = "Beispiel Person";
    person.age = 25;

    // Serialisierung: Speichern der geänderten Daten in einer Datei
    if (person.saveToFile(fileName)) qDebug() << "Geänderte Daten wurden in Datei gespeichert";

    // Serialisierung: Laden der geänderten daten aus der Datei
    if (person.loadFromFile(fileName)) qDebug() << "Daten wurden aus Datei geladen";

    // Anzeige der geänderten Daten
    qDebug() << "Name:" << person.name;
    qDebug() << "Alter:" << person.age;
}

FrmMain::~FrmMain()
{
    delete ui;
}

