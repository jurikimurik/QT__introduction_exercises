#include "constraintmap.h"

ConstraintMap map;              /* OK, ConstaintMap została załączona. */
#include "constraintmap.h"      /* Linia nadmiarowa, ale nieszkodliwa, o ile użyto #ifndef. */

Constraint* constraintP;        /* Użycie deklaracji zapowiadającej z constraintmap.h. */

Constraint p;                   /* Błąd: niekompletny typ. */
#include <constraint.h>
Constraint q;                   /* Teraz typ jest kompletny.  */

void ConstraintMap::addConstraint(Constraint& c) {
    cout << c.name();           /* Tu wymagany jest kompletny typ. */
}






