/*
 * Datei: location.cpp
 * Inhalt: Methoden fuer die Klasse Location
 * Autor: Carlos Paredes, Mahir Dzafic
 * Datum: 2023-06-06
 *
*/

#include "location.h"
#include <QFile>

Location::Location(const QString &name, const QString &address)
{
    this->name = name;
    this->address = address;
}

QString Location::getLocationName()
{
    return name;
}

QString Location::getAddress()
{
    return address;
}

void Location::setLocationName(const QString &name)
{
    this->name = name;
}

void Location::setAddress(const QString &address)
{
    this->address = address;
}

// Operator overload
QDataStream& operator<<(QDataStream &stream, const Location &location)
{
    stream << location.name << location.address;
    return stream;
}

QDataStream& operator>>(QDataStream &stream, Location &location)
{
    stream >> location.name >> location.address;
    return stream;
}

