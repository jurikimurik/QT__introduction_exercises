#include <domwalker.h>

DomWalker::DomWalker(QDomDocument indoc) {
    m_Doc = indoc;
}

QDomElement DomWalker::createElement(QString name) {
    return m_Doc.createElement(name);
}

/**
   Przejście rekurencyjne - zmienia drzewo DOM w miejscu.
   */
//start
QDomDocument DomWalker::transform() {
    walkTree(m_Doc);
    return m_Doc;
}

QDomNode DomWalker::walkTree(QDomNode current) {
    QDomNodeList dnl = current.childNodes();             /* Najpierw rekurencyjnie przetwórz dzieci. */
    for (int i=dnl.count()-1; i >=0; --i)
        walkTree(dnl.item(i));
    if (current.nodeType() == QDomNode::ElementNode) {   /* Przetwarzaj tylko elementy, pozostawiając inne węzły w postaci niezmienionej. */
       QDomElement ce = current.toElement();             /* Zamiast jawnego rzutowania.  */
       return visit(ce);
    }
    return current;
}
//end




