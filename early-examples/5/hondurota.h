#ifndef HONDUROTA_H
#define HONDUROTA_H

#include <QTextStream>
#include <QString>
#include <random>

class Hondurota
{
private:
    std::default_random_engine dre;

    double m_Fuel;
    double m_Odometer;
    double m_TankCapacity;
    double m_MPG;
    double m_Speed;

    static const int m_optimalSpeed = 70;
public:
    Hondurota(double fuel, double odom, double capacity, double mpg);
    double addFuel(double gal);
    double drive(double speed, int minutes);
    QString toString() const;
    double highwayDrive(double distance, double speedLimit);

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
