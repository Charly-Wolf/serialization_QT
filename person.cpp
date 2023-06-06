/*
 * Datei: person.cpp
 * Inhalt: Methoden fuer die Klasse Person
 * Autor: Carlos Paredes, Mahir Dzafic
 * Datum: 2023-06-06
 *
*/

#include "person.h"
#include <QFile>

Person::Person(const QString& firstName, const QString& lastName, int age, Location location)
{
}


QString Person::getFirstName()
{
    return firstName;
}

QString Person::getLastName()
{
    return lastName;
}

int Person::getAge()
{
    return age;
}

Location Person::getLocation()
{
    return location;
}

void Person::setFirstName(const QString &firstName)
{
    this->firstName = firstName;
}

void Person::setLastName(const QString &lastName)
{
    this->lastName = lastName;
}

void Person::setAge(const int &age)
{
    this->age = age;
}

void Person::setLocation(const Location &location)
{
    this->location = location;
}

bool Person::saveToFile(const QString &fileName)
{
    QFile file(fileName); // File into which we save the serialized data

    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream stream(&file);
        serialize(stream);
        file.close();
        return true;
    }
    return false;
}

bool Person::loadFromFile(const QString& fileName)
{
    QFile file(fileName); // File from which we load the serialized data
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&file);
        deserialize(stream);
        file.close();
        return true;
    }
    return false;
}

void Person::deserialize(QDataStream& stream)
{
    stream >> firstName >> lastName >> age >> location;
}

void Person::serialize(QDataStream& stream)
{
    stream << firstName << lastName << age << location;
}
