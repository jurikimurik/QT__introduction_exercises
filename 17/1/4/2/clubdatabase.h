#ifndef CLUBDATABASE_H
#define CLUBDATABASE_H

#include "member.h"

#include <QMainWindow>
#include <QProcess>

#include <QDebug>

namespace Ui {
class ClubDatabase;
}

class ClubDatabase : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClubDatabase(QWidget *parent = nullptr);
    ~ClubDatabase();

private slots:
    void saveMember();
    void trySaveMember();
    void openMember(QString id);


private:
    void updateMemberBox();

private:
    Ui::ClubDatabase *ui;
    QMap<int, Member> m_members;
    QProcess* m_shell;
};

#endif // CLUBDATABASE_H
