/*
 * Datei: location.h
 * Inhalt: Klasse fuer den Standort
 * Autor: Carlos Paredes, Mahir Dzafic
 * Datum: 2023-06-06
 *
*/

#ifndef LOCATION_H
#define LOCATION_H

#include "QString"

class Location
{
    private:
        QString name;
        QString address;

    public:
        Location(const QString& name = "City",
                 const QString& address = "Street 111");

        QString getLocationName();
        QString getAddress();

        void setLocationName(const QString& name);
        void setAddress(const QString &address);

        // Operator overload
        friend QDataStream& operator<<(QDataStream& stream, const Location& location);
        friend QDataStream& operator>>(QDataStream& stream, Location &location);
};

#endif // LOCATION_H
