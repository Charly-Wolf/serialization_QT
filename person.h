#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDataStream>

class Person
{
//    Q_OBJECT
    public:
        QString firstName;
        QString lastName;
        int age;

        Person(const QString& firstName = "FirstName", const QString& lastName = "LastName", int age = 0);

        bool saveToFile(const QString& fileName);
        bool loadFromFile(const QString& fileName);

        void readFromStream(QDataStream& stream);
        void writeToStream(QDataStream& stream);
};

#endif // PERSON_H
