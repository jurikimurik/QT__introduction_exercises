#ifndef DBCONNECTIONSETTINGS_H
#define DBCONNECTIONSETTINGS_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "sqlmdexport.h"
/**
  Prosta klasa zapisująca ustawienia QSqlDatabase w QSettings.
*/

class SQLMDEXPORT DbConnectionSettings
{
public:
    static void save(QSqlDatabase db);
    static QSqlDatabase lastSaved(QString connectionName = QLatin1String( QSqlDatabase::defaultConnection ));

};

#endif // DBCONNECTIONSETTINGS_H
