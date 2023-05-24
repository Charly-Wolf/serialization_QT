#include "location.h"
#include <QFile>

Location::Location(const QString& name)
{
    this->name = name;
}

QString Location::getLocationName()
{
    return this->name;
}

bool Location::setLocationName(const QString &name)
{
    // TO DO: implement validation
    this->name = name;
    return true;
}

// Operator overload
QDataStream& operator<<(QDataStream& stream, const Location& location)
{
    stream << location.name;
    return stream;
}

QDataStream& operator>>(QDataStream& stream, Location& location)
{
    stream >> location.name;
    return stream;
}
