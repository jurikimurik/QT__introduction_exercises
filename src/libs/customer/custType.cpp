#include "custType.h"
#include <qmap.h>

/* Zmienne o zakresie pliku nie zostaną wyeksportowane do innych plików: */

static const QString types = "Corporate,Individual,Educational,Government,Military";

CustomerType::CustomerType(QString typestr) 
{
    fromString(typestr);
}

const NameMap& CustomerType::nameMap() const 
{
    static NameMap s_nameMap;
    static bool initialized = false;
    static const QStringList NAMES = types.split(",");
    return initMap(s_nameMap, NAMES, initialized);
}
