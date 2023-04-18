#ifndef CONSTRAINTMAP_H
#define CONSTRAINTMAP_H

#include <QHash>
#include <QString>

class Constraint;                                           /* Forward declaration. */

class ConstraintMap : public QHash<QString, Constraint*> {  /* Wymaga
      definicji QHash i QString, ale tylko deklaracji Constraint, 
      ponieważ to wskaźnik. */

private:
    Constraint* m_Constraintptr;                            /* Nie ma problemu, to wskaźnik. */
    Constraint m_ConstraintObj;                             /* Błąd: niekompletny typ. */
    void addConstraint(Constraint& c);                      /* Użycie deklaracji zapowiadającej klasę. */
};
#endif        //  #ifndef CONSTRAINTMAP_H
