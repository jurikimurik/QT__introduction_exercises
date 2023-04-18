#include "preference.h"
#include <qmap.h>

	/*  Tworzymy instancję klasy ooEnum.
	  Implementujemy dwukierunkowe odwzorowanie int-string
	  przy użyciu zmiennych statycznych. */

/** Rozdzielona przecinkami lista dozwolonych wartości */

// niezdefiniowany, zły smak, fatalny, kiepski, w miarę, dobry, lepszy, bardzo dobry, perfekcyjny, doskonały
static const QString NAMESSTR = "Undefined=0,Bad Taste=1,Poor=2,Lousy=3,Fair=4,None=5,Good=6,Better=7,Very Good=8,Perfect=9,Excellent=10";
static const QStringList NAMELIST(NAMESSTR.split(","));

static NameMap s_nameMap;
static bool initialized = false;

const NameMap& Preference::nameMap() const {
    return Enum::initMap(s_nameMap, NAMELIST, initialized);
}

/* 
Normalnie nie należy wywoływać funkcji wirtualnych z konstruktora,
	ale tę wywołujemy niewirtualnie -
	kompilator poradzi sobie z decyzją, o którą wersję nam chodzi.
*/

Preference::Preference(QString prefstr) {
    fromString(prefstr);
}


Preference::Preference(int value) : Enum(value) {    
}


