
#include "testdbi.h"

#include <qapplication.h>
#include <qhbox.h>
#include <qcombobox.h>
#include <qmainwindow.h>
#include <qsqlcursor.h>


bool TestDbi::persistentOps () {
    qDebug("testDbi::persistentOps()");
    QSqlDatabase *db = getDbSpec().database();
    Q_ASSERT(db != NULL);
    qDebug("testDbi::mamy bazę danych");
    QStringList tables = db->tables();
    qDebug("Oto lista tabel:");
    qDebug() << tables.join(", ");
    QString tableName = getDbSpec().firstTable();
    qDebug("Tworzymy kursor w pierwszej tabeli %s", tableName);
    QSqlCursor cursor(tableName, true, db);
    // zaznacz wszystkie pola w bazie danych
    cursor.select();
    if ( cursor.next() ) {
        // pobierz pierwszy wiersz jako rekord
        QSqlRecord *record = cursor.editBuffer();
        qDebug("Pierwszy rekord ma %s pól", record->count());
        for (unsigned i=0; i<record->count(); ++i) {
            QString val = QString("%1 = %2").
                          arg(record->fieldName(i)).
                          arg(record->value(i).toString());
            qDebug() << val;
        }
    }
    return true;
}


