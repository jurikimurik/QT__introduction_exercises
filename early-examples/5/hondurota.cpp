#include "hondurota.h"
#include <sstream>
using namespace std;

Hondurota::Hondurota(double fuel, double odom, double capacity, double mpg) :dre(time(nullptr)),
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

    // Przeliczniki
    double miles_per_minute = speed / 60;
    double fuel_consuming_per_minute = miles_per_minute / m_MPG;
    while(minutes > 0)
    {
        // Podczas NIE-optymalnej predkosci, zuzycie paliwa wzrasta
        if(m_Speed > m_optimalSpeed)
        {
            double wspolczynnik = ((m_Speed - m_optimalSpeed) / 100.0 + 1.0);
            fuel_consuming_per_minute *= wspolczynnik;
        }

        m_Fuel -= fuel_consuming_per_minute;
        m_Odometer += miles_per_minute;

        if(m_Fuel <= 0) {
            m_Fuel = 0;
            cout << "Skonczylo sie paliwo!" << Qt::endl;
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

double Hondurota::highwayDrive(double distance, double speedLimit)
{
    if(m_Fuel <= 0)
        return 0;

    uniform_int_distribution id(0, 100);
    int losowosc = id(dre);
    QTextStream cout(stdout);

    if(losowosc > 70 && losowosc < 90)
    {
        cout << "Z powodu warunkow pogodowych, zmniejszona predkosc na autostradzie." << Qt::endl;
        speedLimit *= 0.75;
    } else if(losowosc >= 90 && losowosc <= 100)
    {
        cout << "Wypadek na autostradzie. Predkosc drastycznie zmniejszona." << Qt::endl;
        speedLimit *= 0.20;
    }
    // Predkosciowe odchylenie
    uniform_int_distribution speed_deflection(-5, 5);
    int minutes = distance / (speedLimit / 60);
    int speed = m_Speed + speedLimit;
    while(minutes > 0)
    {
        if(m_Fuel == 0) {
            break;
        }

        int odchylenie = speed_deflection(dre);
        if(speed + odchylenie > speedLimit + 40)
            odchylenie = 0;
        else if(speed + odchylenie < 0)
            while((odchylenie = speed_deflection(dre)) >= 0);

        speed += odchylenie;

        drive(speed, 1);
        minutes--;
    }


    m_Speed = 0;
    return distance / (speedLimit / 60);
}
