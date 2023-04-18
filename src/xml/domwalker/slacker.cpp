#include <slacker.h>
#include <QTextStream>
/*
  Przesłania metodę z DomWalker (klasy bazowej). 
  WalkTree wywołują tę metodę wirtualną na każdym węźle.
  */

//start  
QDomElement Slacker::visit(QDomElement element) {
    QString name = element.tagName();
    
     
    QString cvalue = element.attribute("c", QString()) ;
    if (cvalue != QString()) {                  /* Modyfikacja elementów — wszystkie c= zostaną zamienione na condition=. */
        element.setAttribute("condition", cvalue);
        element.setAttribute("c", QString());
    }
    //end
    /* Dla każdego condition= attribute, dodaj role=  */
    cvalue = element.attribute("condition", QString());
    if (cvalue != QString()) {
        element.setAttribute("role", cvalue);
    }
    
    // Odwzorowywanie elementów
    if (name == "p") {
        element.setTagName("para");
        return element;
    }
    if (name == "ul") {
        element.setTagName("unorderedlist");
        return element;
    }
    //start
    if (name == "b") {
        element.setAttribute("role", "strong");
        element.setTagName("emphasis");
        return element;
    }
    if (name == "li") {                         /* To przekształcenie jest ciekawsze, 
			ponieważ zamieniamy <li> tekst </li> 
			na <listitem><para> tekst </para></listitem>. */
        QDomNode parent = element.parentNode();
        QDomElement listitem = createElement("listitem");
        parent.replaceChild(listitem, element); /* Zastąp znacznik li znacznikiem listitem. */
        element.setTagName("para");             /* Zastąp "w miejscu" nazwę znacznika. */
        listitem.appendChild(element);
        return listitem;
    }
    //end
    
    if (name == "include") { /* zastępuje cały węzeł <include> 
        zawartością załączanego pliku */
        QDomNode parent = element.parentNode();
        QString filename = element.attribute("src");
        FILE* f = fopen(filename.toLatin1(), "r");
        if (f==0) {
            return element;
        }
        QTextStream stream(f, QIODevice::ReadOnly);
        QString text = stream.readAll();
        QDomText tn = this->m_Doc.createTextNode(text);
        QDomElement pl = createElement("programlisting");
        parent.replaceChild(pl, element);
        pl.appendChild(tn);
        return pl;
    }
    return element;
}






