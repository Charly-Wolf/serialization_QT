#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDataStream>

class Person : public QObject
{
    Q_OBJECT
public:
    QString name;
    int age;

    Person(const QString& name = "", int age = 0);

    bool saveToFile(const QString& fileName);
    bool loadFromFile(const QString& fileName);

    void readFromStream(QDataStream& stream);
    void writeToStream(QDataStream& stream);
};

#endif // PERSON_H
