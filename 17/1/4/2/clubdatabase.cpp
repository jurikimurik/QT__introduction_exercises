#include "clubdatabase.h"
#include "ui_clubdatabase.h"

ClubDatabase::ClubDatabase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClubDatabase)
{
    ui->setupUi(this);
    ui->idEdit->setValidator(new QIntValidator(0, 9999, ui->idEdit));
    updateMemberBox();

    m_shell = new QProcess(this);
    m_shell->setProcessChannelMode(QProcess::MergedChannels);
    connect(m_shell, &QProcess::readyReadStandardOutput, this, &ClubDatabase::saveMember);
}

ClubDatabase::~ClubDatabase()
{
    delete ui;
}

void ClubDatabase::saveMember()
{
    int id = ui->idEdit->text().toInt();
    QByteArray password(m_shell->readAllStandardOutput());
    QString email = ui->eMailEdit->text();
    QString address = ui->addressEdit->text();
    QString telephone = ui->telephoneEdit->text();

    m_members.insert(id, Member({id, password, email, address, telephone}));
    updateMemberBox();

    openMember(QString::number(id));
}

void ClubDatabase::trySaveMember()
{
    QString command("/Users/urijmakovskij/crhash \"");
    command += ui->passEdit->text() + QString("\" Md5");
    m_shell->startCommand(command);
}

void ClubDatabase::openMember(QString id)
{
    int memberId = id.toInt();

    Member currentMember = m_members.value(memberId);
    ui->idEdit->setText(QString::number(currentMember.id));
    ui->passEdit->setText(currentMember.password);
    ui->eMailEdit->setText(currentMember.email);
    ui->telephoneEdit->setText(currentMember.telephoneNumber);

    ui->memberBox->setCurrentText(QString::number(memberId));
}

void ClubDatabase::updateMemberBox()
{
    ui->memberBox->clear();
    for(const Member& member: m_members.values())
    {
        ui->memberBox->addItem(QString::number(member.id));
    }
}
