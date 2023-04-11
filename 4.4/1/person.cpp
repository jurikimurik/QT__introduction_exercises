#include "person.h"
#include "position.h"

bool Person::apply(Position *position)
{
    m_Position = position;
    position->setPerson(this);
    return true;
}
