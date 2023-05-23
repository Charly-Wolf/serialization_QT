#include "person.h"
#include <QFile>

Person::Person(const QString& name, int age) : QObject(), name(name), age(age)
{
}

bool Person::saveToFile(const QString &fileName)
{
    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly))
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
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
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
    stream >> name >> age;
}

void Person::writeToStream(QDataStream& stream)
{
    stream << name << age;
}
