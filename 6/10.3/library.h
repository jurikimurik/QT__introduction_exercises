#ifndef LIBRARY_H
#define LIBRARY_H

#include <QString>
#include <QList>

class RefItem {
public:
    virtual ~RefItem();
    QString getItemType() const;
    QString getISBN() const;
    QString getTitle() const;
    int getNumberOfCopies() const;
    virtual QString toString(QString sep="[::]") const;
    void setNumberOfCopies(int newVal);
protected:
    RefItem(QString type, QString isbn, QString title, int numCopies = 1);
    RefItem(QStringList& propList);
private:
    QString m_ItemType, m_ISBN, m_Title;
    int m_NumberOfCopies;
};

class Dvd : public RefItem {
public:

    Dvd(QString type, QString isbn, QString title, QString author, QString pub, double duration, int prodYear, int numCopies = 1);
    Dvd(QStringList& propList);
    virtual QString toString(QString sep = "[::]") const;
    QString getAuthor() const;
    QString getPublisher() const;
    double getFilmDuration() const;
    int getProductionYear() const;

private:
    QString m_Author, m_Publisher;
    double m_FilmDuration;
    int m_ProductionYear;

};

class Book : public RefItem {
public:
    Book(QString type, QString isbn, QString title, QString author, QString pub, int year, int numCopies = 1);
    Book(QStringList& propList);
    virtual QString toString(QString sep = "[::]") const;
    QString getAuthor() const;
    QString getPublisher() const;
    int getCopytightYear() const;
private:
    QString m_Author, m_Publisher;
    int m_CopyrightYear;
};

class ReferenceBook : public Book {
public:
    enum RefCategory {NONE = -1, Art, Architecture, ComputerScience, Literature, Math, Music, Science};
    ReferenceBook(QString type, QString isbn, QString title, QString author, QString pub, int year,RefCategory refcat, int numCopies = 1);
    ReferenceBook(QStringList& propList);
    QString toString(QString sep = "[::]") const;
    RefCategory getCategory() const;
    QString categoryString() const;
    static QStringList getRefCategories();
private:
    RefCategory m_Category;
};

class TextBook : public Book {
public:
    enum Category {NONE = -1, IT, Art, Science, Language, Mechanics};
    TextBook(QString type, QString isbn, QString title, QString author, QString pub, int year, Category cat, int numCopies = 1);
    TextBook(QStringList& propList);
    QString toString(QString sep= "[::]") const;
    Category getCategory() const;
    QString categoryString() const;
    static QStringList getCategories();
private:
    Category m_Category;
};

class Library : public QList<RefItem*>
{
public:
    Library() {}
    ~Library();
    void addRefItem(RefItem*&RefItem);
    int removeRefItem(QString isbn);
    QString toString(QString sep = "\n") const;
    bool isInList(QString isbn);
    QString getItemString(QString isbn);
private:
    Library(const Library&);
    Library& operator=(const Library&);
    RefItem* findRefItem(QString isbn);
};

#endif // LIBRARY_H
