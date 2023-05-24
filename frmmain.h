#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include "person.h"
#include "location.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FrmMain; }
QT_END_NAMESPACE

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

    // Helper Functions
    void getUserInput();
    void clearInputFields();
    void outputData();
    void saveFileDialog();
    bool openFileDialog();
    QString getFileName(const QString& filePath);
    void setLineEdits(const QString& firstName, const QString& lastName, int age, Location location);
    void fillLocationsList();
    void sortLocations();

// Button Funtions
private slots:
    void on_btn_save_clicked();
    void on_btn_open_clicked();
    void on_btn_clear_clicked();

private:
    Ui::FrmMain *ui;
    Person person;
    QList<Location> locations;
};
#endif // FRMMAIN_H
