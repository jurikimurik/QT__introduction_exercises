#include "hondurota.h"
#include <sstream>

Hondurota::Hondurota(double fuel, double odom, double capacity, double mpg) :
    m_Fuel(fuel), m_Odometer(odom), m_TankCapacity(capacity), m_MPG(mpg), m_Speed(0) {}

double Hondurota::addFuel(double gal)
{
    if(gal == 0)
    {
        m_Fuel = m_TankCapacity;
        return m_Fuel;
    } else if(m_Fuel + gal <= m_TankCapacity)
        m_Fuel += gal;
    else
        m_Fuel = m_TankCapacity;

    return m_Fuel;
}

double Hondurota::drive(double speed, int minutes)
{
    QTextStream cout(stdout);

    if(m_Fuel == 0)
        return 0;

    // Rozpedzamy samochod
    m_Speed = speed;

    //Ile mieliscmy przejechac
    int minutes_need = minutes;

    // Przeliczniki
    double miles_per_minute = speed / 60;
    double fuel_consuming_per_minute = miles_per_minute / m_MPG;
    while(minutes > 0)
    {
        m_Fuel -= fuel_consuming_per_minute;
        m_Odometer += miles_per_minute;

        if(m_Fuel <= 0) {
            m_Fuel = 0;
            cout << "Skonczylo sie paliwo na " << minutes_need - minutes << " minucie! O nie!" << Qt::endl;
            break;
        }

        minutes--;
    }

    m_Speed = 0;
    return m_Fuel;
}

QString Hondurota::toString() const {
    std::stringstream strm;
    strm << "Ilosc paliwa: " << m_Fuel << ", "
         << "Drogomierz: " << m_Odometer << ", "
         << "Pojemnosc: " << m_TankCapacity << ", "
         << "Zuzycie na mile: " << m_MPG << ", "
         << "Szybkosc teraz: " << m_Speed << ", ";
    return QString::fromStdString(strm.str());
}
