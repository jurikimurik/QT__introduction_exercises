#ifndef SLACKER_H
#define SLACKER_H

#include "domwalker.h"
/**
 
   Slacker.h 
   
   Przekształca podzbiór elementów Slacker's Docbook/XML na
   100% poprawny format Docbook/XML.
 
   Większość znaczników z grupy slacker to zapożyczenia z HTML,
   skracające popularne znaczniki docbook.
   
   Wersja 0.01 pre-alpha. Obecnie obsługuje jedynie niewielki 
   podzbiór elementów.
   
   Autor: S. Alan Ezust  ezust at users dot sourceforge dot net
           http://cartan.cas.suffolk.edu/~sae/local
  */

class Slacker : public DomWalker {
public:
    Slacker(QDomDocument doc) : DomWalker(doc) {}

    /**
      Zmienia w miejscu drzewo XML.
    * @param current - aktualnie odwiedzany element drzewa
    * @return current,lub inny węzeł, który ma zastąpić current.
    */
    virtual QDomElement visit(QDomElement current);
};

#endif        //  #ifndef SLACKER_H

