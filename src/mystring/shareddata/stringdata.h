#ifndef STRINGDATA_H
#define STRINGDATA_H

#include "mystring.h"
#include <QSharedData>
 
/** Przykładowy typ QSharedData dla SString 
	prywatna implementacja domyślnie współdzielonego łańcucha znaków
    */
//start
class StringData : public QSharedData, public MyString {
public:
    friend class SString;
    StringData() {}
    StringData(const char* d) : MyString(d) {}
    explicit StringData(int len) : MyString(len) {}
    StringData(const StringData& other) 
             : QSharedData(other), MyString(other) {}    
};
//end
#endif        //  #ifndef STRINGDATA_H
