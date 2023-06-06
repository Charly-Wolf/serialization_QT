#ifndef PERSON_H
#define PERSON_H

#include <QDataStream>
#include <location.h>

class Person
{
    private:
        QString firstName;
        QString lastName;
        int age;
        Location location;

    public:
        Person(const QString& firstName = "FirstName",
               const QString& lastName = "LastName",
               int age = 0,
               Location location = Location("Location"));

        QString getFirstName();
        QString getLastName();
        int getAge();
        Location getLocation();

        void setFirstName(QString firstName);
        void setLastName(QString lastName);
        void setAge(int age);
        void setLocation(Location location);

        bool saveToFile(const QString& fileName);
        bool loadFromFile(const QString& fileName);

        void readFromStream(QDataStream& stream);
        void writeToStream(QDataStream& stream);
};

#endif // PERSON_H
