#include "library.h"
#include <QStringList>
#include <QDebug>

RefItem::RefItem(QStringList &plst) : m_ItemType(plst.takeFirst()), m_ISBN(plst.takeFirst()),
    m_Title(plst.takeFirst()), m_NumberOfCopies(plst.takeFirst().toInt())
{}


QString RefItem::toString(QString sep) const {
    return
        QString("%1%2%3%4%5%6%7").arg(m_ItemType).arg(sep).arg(m_ISBN).arg(sep).arg(m_Title).arg(sep).arg(m_NumberOfCopies);
}

void RefItem::setNumberOfCopies(int newVal) {
    m_NumberOfCopies = newVal;
}

RefItem::~RefItem()
{}

int RefItem::getNumberOfCopies() const {
    return m_NumberOfCopies;
}

QString RefItem::getISBN() const {
    return m_ISBN;
}
//------------------------------------------------------
Dvd::Dvd(QStringList &plst) : RefItem(plst), m_Author(plst.takeFirst()), m_Publisher(plst.takeFirst()), m_FilmDuration(plst.takeFirst().toDouble()), m_ProductionYear(plst.takeFirst().toInt())
{}

QString Dvd::toString(QString sep) const {
    return QString("%1%2%3%2%4%2%5%2%6").arg(RefItem::toString(sep)).arg(sep).arg(m_Author).arg(m_Publisher).arg(QString::number(m_FilmDuration)).arg(QString::number(m_ProductionYear));
}
//------------------------------------------------------
Book::Book(QStringList &plst) : RefItem(plst), m_Author(plst.takeFirst()), m_Publisher(plst.takeFirst()), m_CopyrightYear(plst.takeFirst().toInt())
{}

QString Book::toString(QString sep) const {
    return  QString("%1%2%3%4%5%6%7").arg(RefItem::toString(sep)).arg(sep).arg(m_Author).arg(sep).arg(m_Publisher).arg(sep).arg(m_CopyrightYear);
}
//------------------------------------------------------
ReferenceBook::ReferenceBook(QStringList &plst) : Book(plst), m_Category(static_cast<RefCategory>(plst.takeFirst().toInt()))  {}

QString ReferenceBook::toString(QString sep) const {
    return QString("%1%2%3").arg(Book::toString(sep)).arg(sep).arg(categoryString());
}

QString ReferenceBook::categoryString() const {
    switch(m_Category) {
        case Art: return "Sztuka";
        case Architecture: return "Architektura";
        case ComputerScience: return "Informatyka";
        case Literature:  return "Literatura";
        case Math:  return "Matematyka";
        case Music:  return "Muzyka";
        case Science:  return "Nauki scisle";
        default: return "Brak";
    }
}

QStringList ReferenceBook::getRefCategories() {
    return QStringList({"Sztuka", "Architektura", "Informatyka", "Literatura", "Matematyka", "Muzyka", "Nauki scisle"});
}
//------------------------------------------------------
TextBook::TextBook(QStringList &plst) : Book(plst), m_Category(static_cast<Category>(plst.takeFirst().toInt()))
{}

QString TextBook::toString(QString sep) const {
    return QString("%1%2%3").arg(Book::toString(sep)).arg(sep).arg(categoryString());
}

QString TextBook::categoryString() const {
    switch(m_Category) {
    case IT: return "Informatyka";
    case Art: return "Sztuka";
    case Science: return "Nauki scisle";
    case Language: return "Nauka jezyka";
    case Mechanics: return "Mechanika";
    default: return "Brak";
    }
}

QStringList TextBook::getCategories() {
    return QStringList({"Informatyka", "Sztuka", "Nauki scisle",
                        "Nauka jezyka", "Mechanika"});
}
//------------------------------------------------------

Library::~Library() {
    qDeleteAll(*this);
    clear();
}

Library::Library(const Library&) : QList<RefItem*>() {}

Library& Library::operator= (const Library&) {
    return *this;
}

void Library::addRefItem(RefItem *&refitem)
{
    QString isbn(refitem->getISBN());
    RefItem* oldItem(findRefItem(isbn));
    if(oldItem == nullptr)
        append(refitem);
    else {
        qDebug() << isbn << " Juz na liscie:\n"
                 << oldItem->toString()
                 << "\nZwiekszam liczbe kopii "
                 << "i usuwam nowy wskaznik.";
        int newNum(oldItem->getNumberOfCopies() + refitem->getNumberOfCopies());
        oldItem->setNumberOfCopies(newNum);
        delete refitem;
        refitem = nullptr;
    }
}

int Library::removeRefItem(QString isbn) {
    RefItem* ref(findRefItem(isbn));
    int numCopies(-1);
    if(ref) {
        numCopies = ref->getNumberOfCopies() - 1;
        if(numCopies == 0) {
            removeAll(ref);
            delete ref;
        } else
            ref->setNumberOfCopies(numCopies);
    }
    return numCopies;
}

RefItem* Library::findRefItem(QString isbn) {
    for(int i = 0; i < size(); ++i) {
        if(at(i)->getISBN().trimmed() == isbn.trimmed())
            return at(i);
    }
    return nullptr;
}

bool Library::isInList(QString isbn) {
    return findRefItem(isbn);
}

QString Library::toString(QString sep) const {
    QStringList reflst;
    for(int i = 0; i < size(); ++i)
    {
        reflst << at(i)->toString();
    }
    return reflst.join(sep);
}

QString Library::getItemString(QString isbn) {
    RefItem* ref(findRefItem(isbn));
    if(ref)
        return ref->toString();
    else
        return QString();
}
