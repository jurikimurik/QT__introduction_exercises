#include "textbook.h"
#include <QMap>
#include <QDebug>


//start id=impl
TextbookMap::~TextbookMap() {
    qDebug() << "Usuwam TextbookMap ..." << endl;
    qDeleteAll(values());
    clear(); 
}

void TextbookMap::add(Textbook* text) {
    insert(text->getIsbn(), text);
}

QString TextbookMap::toString() const {
    QString retval;
    QTextStream os(&retval);
    ConstIterator itr = constBegin();
    for ( ; itr != constEnd(); ++itr)
        os << '[' << itr.key() << ']' << ": "
        << itr.value()->toString() << endl;
    return retval;
}
//end
//start id=client
int main() {
    Textbook* t1 = new Textbook("Język C++",
        "Stroustrup", "0201700735", 1997);
    Textbook* t2 = new Textbook("XML w pigułce", 
        "Harold","0596002920", 2002);
    Textbook* t3 = new Textbook("Wzorce projektowe ", 
        "Fowler", "0321193687", 2004);
    Textbook* t4 = new Textbook("Wzorce projektowe", "Gamma",
        "0201633612",1995);
    {                                                ///1
        TextbookMap m;
        m.add(t1);
        m.add(t2);
        m.add(t3);
        m.add(t4);
        qDebug() << m.toString();
        m.remove (t3->getIsbn());                    ///2
    }                                                ///3
    qDebug() << "Po zniszczeniu m ciągle mamy:\n" 
        << t3->toString();
    return 0;
}

//end
