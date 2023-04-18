#ifndef SSTRING_H
#define SSTRING_H

#include "stringdata.h"
#include <QSharedDataPointer>
#include <iostream>
//start
/** Demonstracja QSharedDataPointer z współdzielonym łańcuchem znaków */
class SString {
public:
    SString();
    explicit SString(int len);
    SString(const char* ptr);
    SString& operator+= (const SString& other);
    int length() const;
    int refcount() const {return m_d->ref;}
    friend SString operator+(SString, SString);
    friend std::ostream& operator<< (std::ostream&, const SString&);
//end    
    /** for debugging purposes only */
    qlonglong sharedDataAddress() const;

 /* Wygenerowane przez kompilator wersje interesujących nas elementów: 
    SString(const SString& other);
    SString& operator= (const SString& other); */
//start    
private:
    // Wzorzec Implementacja Prywatna
    QSharedDataPointer<StringData> m_d;
    
};
//end

#endif        //  #ifndef SSTRING_H
