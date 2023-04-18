#include <QtWidgets>
#include <QtSql>
#include "ui_DbConnectionForm.h"
#include "dbconnectionform.h"
#include "dbconnectionsettings.h"

DbConnectionForm::DbConnectionForm(QWidget* parent)
    : QDialog(parent)
{
    db = DbConnectionSettings::lastSaved();
    ui = new Ui::DbConnectionForm();
    ui->setupUi(this);

    ui->driverCombo->clear();
    ui->driverCombo->addItems(QSqlDatabase::drivers());

    if (!db.isValid()) return;
    int comboIdx = ui->driverCombo->findText(db.driverName());
    if (comboIdx > 0)
        ui->driverCombo->setCurrentIndex(comboIdx);


    ui->passwordLineEdit->setText(db.password());
    ui->hostLineEdit->setText(db.hostName());

    ui->userLineEdit->setText(db.userName());
    QSettings s;
    QString path = s.value("db.path", QStandardPaths::standardLocations(
            QStandardPaths::DataLocation).first()).toString();
    ui->dbFileLineEdit->setText(path);
    ui->databaseLineEdit->setText(db.databaseName());
    QTimer::singleShot(2000, this, SLOT(on_driverCombo_activated()));
}

bool DbConnectionForm::isFileBased() const {
    QString driverName = ui->driverCombo->currentText();
    return !driverName.isNull() && driverName.startsWith("QSQLITE");
}

void DbConnectionForm::on_browseButton_clicked() {

    QString path = ui->dbFileLineEdit->text();
    QFileInfo fi(path);
    QDir dir = fi.absoluteDir();

    QFileDialog fd;
    fd.setFileMode(QFileDialog::AnyFile);
    fd.setDirectory(dir);
    fd.setWindowTitle("Wybierz nowy lub istniejący plik bazy danych.");
    if (fd.exec()) {
        QStringList sl = fd.selectedFiles();
        ui->dbFileLineEdit->setText(sl[0]);
    }
}


void DbConnectionForm::accept() {

    // Niech to będzie domyślna baza danych
    db = QSqlDatabase::addDatabase(ui->driverCombo->currentText());
    if (isFileBased()) {
        db.setDatabaseName(ui->dbFileLineEdit->text());
    }
    else {
        db.setDatabaseName(ui->databaseLineEdit->text());
    }
    db.setPassword(ui->passwordLineEdit->text());
    db.setHostName(ui->hostLineEdit->text());
    db.setUserName(ui->userLineEdit->text());
    if (!db.open()) {
        QMessageBox::critical(this, "Nie udało się połączyć z bazą danych", db.lastError().text());
    }
    else {
        if (isFileBased()) {
            QSettings s;
            s.setValue("db.path", db.databaseName());
        }
        DbConnectionSettings::save(db);
        QDialog::accept();
    }
}



void DbConnectionForm::on_driverCombo_activated(QString )
{
    if (isFileBased()) {
        ui->pwFrame->hide();
        ui->fileNameFrame->show();
    }
    else {
        ui->fileNameFrame->hide();
        ui->pwFrame->show();
    }
}
