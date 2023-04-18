#ifndef EGG_H
#define EGG_H
//start
class Chicken;              /* Zapowiedź klasy. */
class Egg {
 public:
    Chicken* getParent();   /* Dozwolone w deklaracjach, jeśli mamy do czynienia ze wskaźnikami. */ 
};
//end
#endif        //  #ifndef EGG_H
