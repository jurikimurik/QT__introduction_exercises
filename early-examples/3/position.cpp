#include "position.h"

Position::Position(string name, string description) : m_Name(name), m_Description(description) {}

string Position::toString()
{
    return m_Description;
}
