#ifndef DOCBOOKWALKER_H
#define DOCBOOKWALKER_H
#include <QChar>
#include <QStringList>
#include "docbookdoc.h"
#include "docbook_export.h"

/** Klasa przechodząca przez i przekształcająca dokumenty Docbook.
    Śledzi numery sekcji i rozdziałów.
	@author Alan Ezust
 */
class DOCBOOK_EXPORT DocbookWalker {
 public:
    DocbookWalker(DocbookDoc doc);
    /** Przechodzi przez całe drzewo. */
    virtual QDomDocument transform();
    virtual ~DocbookWalker() {}
    /**
    @return liczba odwiedzonych węzłów
    */
    virtual int visited() const { 
        return m_visited; 
    } 
 protected:

    /** Odwiedza aktualny element.
        Obsługuje elementy takie jak <chapter>, <section> i
        <appendix> i numeruje je.

        Wywoływana przez walkTree z transform.
        Nie należy jej wywoływać publicznie.
        
        Możesz przesłonić tę metodę, obsłużyć konkretne elementy,
		a następnie wywołać wersję z klasy bazowej dla elementów, 
		których nie obsługujesz.		
    @param e element do odwiedzenia
    @param depth aktualna głębokość drzewa
    @return false jeśli po obslużeniu tego obiektu nie mamy sprawdzać dzieci. 
    */
    virtual bool visit(int depth, Element e) ;

    /** @return Dla aktualnego rozdziału/sekcji/dodatku zwraca w postaci QString nazwę elementu, po której następuje numer i tytuł. */
    QString currentHeading() const;
    
    /**
      @param sect rozdział, sekcja lub dodatek
      @return nagłówek sekcji */
    QString heading(Element sect) const;

    QDomNode walkTree(int depth, QDomNode current);

    void newChapter(Element e);
    void newSection(Element e, int depth);
    void newAppendix(Element e) ;
    
    Element& currentChapter() {
        return m_currentChapter;
    }
    Element& currentSection() {
        return m_currentSection;
    }
    
    
 protected:
    mutable DocbookDoc m_document;


 private:
    Element m_currentChapter;
    Element m_currentSection;
    int m_chapt;
    int m_appendix;
    int m_visited;
    QList<int> m_sectNum;
};
#endif        //  #ifndef DOCBOOKWALKER_H
