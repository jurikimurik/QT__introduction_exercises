#include "employer.h"

Employer::Employer(string name, string market) : m_Name(name), m_market(market) {}

string Employer::toString()
{
    return m_Name + " - " + m_market;
}
