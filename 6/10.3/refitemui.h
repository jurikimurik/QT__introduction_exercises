#ifndef REFITEMUI_H
#define REFITEMUI_H


#include <QStringList>
#include "library.h"

class RefItemUI
{
public:
    RefItemUI();
    ~RefItemUI();
    QStringList prompt();
};

class BookUI : public RefItemUI
{
public:
    BookUI();
    QStringList prompt();
};

class ReferenceBookUI : public BookUI
{
public:
    ReferenceBookUI();
    QStringList prompt();
};

class TextBookUI : public BookUI
{
public:
    TextBookUI();
    QStringList prompt();
};


class DvdUI : public RefItemUI
{
public:
    DvdUI();
    QStringList prompt();
};

class FilmUI : public DvdUI
{
public:
    FilmUI();
    QStringList prompt();
};

class DataBaseUI : public DvdUI
{
public:
    DataBaseUI();
    QStringList prompt();
};

#endif // REFITEMUI_H
