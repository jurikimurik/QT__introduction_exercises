#ifndef DOCBOOKDOC_H
#define DOCBOOKDOC_H

#include "docbook_export.h"
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
//start id=typedef
typedef QDomElement Element; /* Taki alias oszczędza liczbę znaków, a przy okazji jest zgodny ze specyfikacją Java DOM. */
//end
   
/** Dokument docbook/XML
    @author Alan Ezust
	
*/   
class DOCBOOK_EXPORT DocbookDoc : public QDomDocument {
   public:
    DocbookDoc(QString title);

    /** @return nowy element <title> (rozdział) z rodzicem ustawionym na parent. */
    Element title(QString title, Element parent = Element());
    
    /** @return nowy dziecko bridgehead */
    Element bridgehead(QString title);
    
    Element orderedlist();
        
    
    /** @return nowy element <chapter> (rozdział) z tytułem;
       dziecko korzenia dokumentu */
    Element chapter(QString title);
   
    /**
     @return prosty element xref */
    Element xref(QString id) ;
    /** @return xref w nawiasie wewnątrz para */
    Element xrefP(QString id) ;
    
    /** @return nowy element section; dziecko ostatnio utworzonego chapter.  */
    Element section(QString title);
    
    /** @return nowy appendix (dodatek) */
    Element appendix(QString title);
    
    /** @return wytłuszczony tekst bez rodzica */
    Element bold(QString boldText);

    Element listitem();
    
    /** @return tytuł elementu, jeśli istnieje */
    QString getTitle(Element el) const;
    
    /** @return nowy akapit z tytułem;
		dziecko ostatnio utworzonego rozdziału lub sekcji */
    Element formalpara(QString title, QString text);
    /** @return an ordinary paragraph */
    Element para(QString text);
    
    /** @return element simplesect z tytułem */
    Element simplesect(QString titleStr) ;
    
    /** @param el Element, któremu chcesz przypisać atrybut
        @param role - warunek, który chcesz ustawić
    */
    static void setRole(Element el, QString role); 

    Element currentParent; /* Wszystkie nowe akapity trafią do tego rodzica */

    Element currentPara;
    
    Element currentChapter; /* Tu trafią nowe sekcje */
    
    Element currentList; /* Tu trafią nowe listitem */
};

inline Element& operator<<(Element& parent, QDomNode newChild) {
    parent.appendChild(newChild);
    return parent;
}


#endif        //  #ifndef DOCBOOKDOC_H
