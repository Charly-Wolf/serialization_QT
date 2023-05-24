#include "person.h"
#include <QFile>

Person::Person(const QString& firstName, const QString& lastName, int age, Location location)
{
}

bool Person::saveToFile(const QString &fileName)
{
    QFile file(fileName); // File into which we save the serialized data

    if (file.open(QIODevice::WriteOnly)) // TO DO: Add comment to explain what QIODevice::WriteOnly does
    {
        QDataStream stream(&file);
        writeToStream(stream);
        file.close();
        return true;
    }
    return false;
}

bool Person::loadFromFile(const QString& fileName)
{
    QFile file(fileName); // File from which we load the serialized data
    if (file.open(QIODevice::ReadOnly)) // TO DO: Add comment to explain what QIODevice::ReadOnly does
    {
        QDataStream stream(&file);
        readFromStream(stream);
        file.close();
        return true;
    }
    return false;
}

void Person::readFromStream(QDataStream& stream)
{
    stream >> firstName >> lastName >> age >> location;
}

void Person::writeToStream(QDataStream& stream)
{
    stream << firstName << lastName << age << location;
}
