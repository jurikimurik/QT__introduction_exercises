#ifndef DBCONNECTIONFORM_H
#define DBCONNECTIONFORM_H

#include <QDialog>
#include <QSqlDatabase>
#include "sqlmdexport.h"
/** Formularz bazy danych QSqlDatabase korzystający z delegacji
 */

class DbPlayListItem;

namespace Ui {
    class DbConnectionForm;
}


class SQLMDEXPORT DbConnectionForm : public QDialog
{
    Q_OBJECT
public:
    DbConnectionForm(QWidget* parent=0);
    QSqlDatabase db;
    DbPlayListItem* createItem();
    bool isFileBased() const ;
public slots:
    void accept();
    void on_browseButton_clicked();

private:
    void populateCombo();
    Ui::DbConnectionForm* ui;


private slots:
    void on_driverCombo_activated(QString v = QString() );
};


#endif // DBCONNECTIONFORM_H
