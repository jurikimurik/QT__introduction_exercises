#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H


#include <QProcess>

/** Menedżer haseł w stylu auth, do stosowania z htpasswd */
class PasswordManager : public QProcess {
	Q_OBJECT
	public:
	
	PasswordManager();
	virtual ~PasswordManager() {}

	/** @return hasło SHA1 z pliku "auth", jeśli tam jest,
		lub pusty łańcuch znaków, jeśli użytkownik jeszcze nie został zarejestrowany */
	QString getPassword(QString userName);

	/** @return true jeśli hasło użytkownika jest poprawne. */
	bool checkPassword (QString userName, QString password);

	/** Tworzy użytkownika
		@return true jeśli się udało, false jeśli nie (na przykład użytkownik już istnieje)
	*/
	bool addUser(QString userName, QString password);
	
	/**
	  Zmienia hasło, jeśli dotychczasowe hasło oldPassword jest poprawne
	  */
	bool changePassword(QString userName, QString oldPassword, QString newPassword);
	
    protected:
	void setPassword(QString userName, QString password);
	
};

#endif        //  #ifndef PASSWORDMANAGER_H

