#ifndef HONDUROTA_H
#define HONDUROTA_H

#include <QTextStream>
#include <QString>

class Hondurota
{
private:
    double m_Fuel;
    double m_Odometer;
    double m_TankCapacity;
    double m_MPG;
    double m_Speed;
public:
    Hondurota(double fuel, double odom, double capacity, double mpg);
    double addFuel(double gal);
    double drive(double speed, int minutes);
    QString toString() const;

    //------------------------------------------------------------------
    double getSpeed() const {
        return m_Speed;
    }
    double getTankCapacity() const {
        return m_TankCapacity;
    }
    double getMPG() const {
        return m_MPG;
    }
    double getFuel() const {
        return m_Fuel;
    }
    double getOdometer() const {
        return m_Odometer;
    }


};

#endif // HONDUROTA_H
