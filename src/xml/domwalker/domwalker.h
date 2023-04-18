#ifndef DomWalker_H
#define DomWalker_H

/**
  Kolejny przykład wzorca Odwiedzający -
  ta klasa przechodzi przez drzewo DOM.
*/
#include <QDomNode>
#include <QDomElement>
#include <QDomDocument>

/**
   DomWalker to prosta klasa przekształcająca DOM,
   umożliwiająca modyfikację drzew XML "w miejscu".
   
   Możesz przesłonić metodę visit() jako operację wykonywaną na każdym elemencie,
   a następnie wywołać tranform().    
   */

class DomWalker {
public:
    /**
      @param doc dokument, który chcesz przekształcić
    */

    DomWalker(QDomDocument doc);
    virtual ~DomWalker() {}

    /**
       Przesłoń tę metodę, jeśli chcesz zrobić coś z elementem QDomElement
		w czasie odwiedzin. */

    virtual QDomElement visit(QDomElement current)=0;

    /**
    Wywołuje visit() na każdym elemencie.          
    */
    QDomDocument transform();

protected:
    QDomNode walkTree(QDomNode current);
    QDomElement createElement(QString name);
    QDomDocument m_Doc;

};


#endif        //  #ifndef DomWalker_H

