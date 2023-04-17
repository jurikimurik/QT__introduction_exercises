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
Film::Film(QStringList &propList) : Dvd(propList), m_Category(static_cast<Category>(propList.takeFirst().toInt()))
{}

QString Film::toString(QString sep) const {
    return QString("%1%2%3").arg(Dvd::toString(sep)).arg(sep).arg(categoryString());
}

QString Film::categoryString() const {
    switch(m_Category) {
    case Science: return "Nauka";
    case IT: return "Informatyka";
    case Language: return "Nauka jezyka";
    case Action: return "Akcja";
    case Sci_Fi: return "Naukowo-fantastyczny";
    case Adventure: return "Przygodowy";
    default: return "Brak";
    }
}

QStringList Film::getCategories() {
    return QStringList({"Nauka", "Informatyka", "Nauka jezyka", "Akcja",
                        "Naukowo-fantastyczny", "Przygodowy"});
}
//------------------------------------------------------
DataBase::DataBase(QStringList &plst) : Dvd(plst), m_Category(static_cast<Category>(plst.takeFirst().toInt())),
    m_ShortDescription(plst.takeFirst()), m_isPasswordProtected((plst.takeFirst() == "Chroniony" ? true : false)), m_Password((plst.isEmpty() ? QString() : plst.takeFirst()))
{}

QString DataBase::toString(QString sep) const {
    return QString("%1%2%3%2%4%2%5%2%6").arg(Dvd::toString(sep)).arg(sep).arg(categoryString()).arg(m_ShortDescription).arg((m_isPasswordProtected ? "Chroniony" : "Bez hasla")).arg(m_Password.size() > 0 ? m_Password : "Brak hasla");
}

QString DataBase::categoryString() const {
    switch(m_Category) {
    case FAMILY_HISTORY: return "Historia rodu";
    case TELEPHONE_NUMBERS: return "Numery telefonow";
    case ADDRESSES: return "Adresy";
    case MAPS: return "Mapy";
    case TOURISTS_GUIDE: return "Przewodnik turystyczny";
    case BIBLIOGRAPHY: return "Bibliografia";
    default: return "Brak";
    }
}

QStringList DataBase::getCategories() {
    return QStringList({"Historia rodu", "Numery telefonow", "Adresy", "Mapy", "Przewodnik turystyczny", "Bibliografia"});
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

Library::Library(const Library&) : QMap<QString, RefItem*>() {}

Library& Library::operator= (const Library&) {
    return *this;
}

void Library::addRefItem(RefItem *&refitem)
{
    QString isbn(refitem->getISBN());
    RefItem* oldItem(findRefItem(isbn));
    if(oldItem == nullptr)
        insert(isbn, refitem);
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
    int numCopies(-1);
    auto pos = find(isbn);
    if(pos != end()) {
        numCopies =  (*pos)->getNumberOfCopies() - 1;
        if(numCopies == 0) {
            remove(isbn);
        } else
            (*pos)->setNumberOfCopies(numCopies);
    }
    return numCopies;
}

RefItem* Library::findRefItem(QString isbn) {
    auto pos = find(isbn);
    if(pos == end())
        return nullptr;
    else
        return *pos;
}

bool Library::isInList(QString isbn) {
    return (find(isbn) != end());
}

QString Library::toString(QString sep) const {
    QStringList reflst;
    for(const auto& elem : *this)
    {
        reflst << elem->toString();
    }
    return reflst.join(sep);
}

QString Library::getItemString(QString isbn) {
    auto pos = find(isbn);
    if(pos != end())
        return (*pos)->toString();
    else
        return QString();
}
