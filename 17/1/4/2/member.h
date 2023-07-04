#ifndef MEMBER_H
#define MEMBER_H

#include <QString>



struct Member
{
    int id = 0;
    QByteArray password = "";
    QString email = "";
    QString address = "";
    QString telephoneNumber = "";
};

#endif // MEMBER_H
