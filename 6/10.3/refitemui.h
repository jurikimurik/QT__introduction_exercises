#ifndef REFITEMUI_H
#define REFITEMUI_H


#include <QStringList>
#include "library.h"

class RefItemUI
{
private:
    RefItem* m_Ptr;
public:
    RefItemUI(RefItem* wsk);
    ~RefItemUI();
    QStringList prompt();
};

class BookUI : public RefItemUI
{
public:
    BookUI(Book* wsk);
    QStringList prompt();
};

class ReferenceBookUI : public BookUI
{
public:
    ReferenceBookUI(ReferenceBook* wsk);
    QStringList prompt();
};

class TextBookUI : public BookUI
{
public:
    TextBookUI(TextBook* wsk);
    QStringList prompt();
};


class DvdUI : public RefItemUI
{
public:
    DvdUI(Dvd* wsk);
    QStringList prompt();
};

class FilmUI : public DvdUI
{
public:
    FilmUI(Film* wsk);
    QStringList prompt();
};

class DataBaseUI : public DvdUI
{
public:
    DataBaseUI(DataBase* wsk);
    QStringList prompt();
};

#endif // REFITEMUI_H
