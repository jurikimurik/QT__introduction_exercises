#ifndef LIBRARYUI_H
#define LIBRARYUI_H

#include "library.h"


class LibraryUI
{
public:
    enum Choices {READ = 1, ADD, FIND, REMOVE, SAVE, LIST, QUIT};
    enum Types {BOOK, REFERENCEBOOK, TEXTBOOK, DVD, FILM, DATADVD};
    const QStringList TYPES = (QStringList() << "KSIAZKA" << "INFORMATOR" << "PODRECZNIK" << "DVD" << "FILM" << "DVDZDANYMI");
private:
    Library* m_Lib;
public:
    LibraryUI(Library *lib);
    void add(QStringList objdata);
    void read();
    void enterData();
    QString find();
    void remove();
    void save();
    void list();
    QStringList promptRefItem();
    QStringList promptBook();
    QStringList promptReferenceBook();
  //QStringList promptTextBook();
  //QStringList promptDvd();
  //QStringList promptFilm();
  //QStringList promptDataBase();
    Choices nextTask();
    void prepareToQuit(bool& saved);



};

#endif // LIBRARYUI_H
