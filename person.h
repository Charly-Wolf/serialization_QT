#ifndef PERSON_H
#define PERSON_H

#include <QDataStream>
#include <location.h>

//Commit-Test
//Commit-Test2
class Person
{
    public: // TO DO: User Private attributes and public getters and setters!!
        QString firstName;
        QString lastName;
        int age;
        Location location;

        Person(const QString& firstName = "FirstName",
               const QString& lastName = "LastName",
               int age = 0,
               Location location = Location("Location"));

        bool saveToFile(const QString& fileName);
        bool loadFromFile(const QString& fileName);

        void readFromStream(QDataStream& stream);
        void writeToStream(QDataStream& stream);
};

#endif // PERSON_H
