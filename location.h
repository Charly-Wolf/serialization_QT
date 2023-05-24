#ifndef LOCATION_H
#define LOCATION_H

#include "QString"

class Location
{
    private:
        QString name;

    public:
        Location(const QString& name = "Location");
        QString getLocationName();
        bool setLocationName(const QString& name);

        // Operator overload
        friend QDataStream& operator<<(QDataStream& stream, const Location& location);
        friend QDataStream& operator>>(QDataStream& stream, Location& location);
};

#endif // LOCATION_H
