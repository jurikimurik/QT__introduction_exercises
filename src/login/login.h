#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMainWindow>
//#include <QMap>
//#include <QDialog>
//#include <QLineEdit>

class User;
class QAction;
class QEvent;
class QLineEdit;
class QPushButton;
class QActionGroup;
class QStackedWidget;
class QVBoxLayout;
//class QHBoxLayout;
class PasswordManager;


/** Klasa bazowa dla formularzy logowania, zawierających użytkownika i hasło. */
class LoginPanel : public QWidget {
    Q_OBJECT
 public:
    LoginPanel(QWidget* parent=0) ;

 signals:
    /** Emitowany po wciśnięciu przycisku ok.
		Panel logowania nie uwierzytelnia użytkownika. 
        @param user wartość wprowadzona jako nazwa użytkownika
        @param password wartość wprowadzona jako hasło
        */
    void login(QString user, QString password);

 public slots: 
    virtual void ok();
    virtual void cancel();
    
 protected:
    QLineEdit* m_nameLine;
    QLineEdit* m_passLine;
    QVBoxLayout* m_mainLayout;
    QWidget* m_buttons;
    QWidget* m_nameWidget;
    QWidget* m_passWidget;
    QPushButton* m_Ok;
    QPushButton* m_Cancel;
};


class RegisterPanel : public LoginPanel {
    Q_OBJECT
 public:
    RegisterPanel(QWidget* parent=0);

 public slots:
    virtual void ok();
   signals:
    /** Emitowany po wciśnięciu przycisku ok.
        RegisterPanel najpierw sprawdza, czy wartość passVerifyLine odpowiada wartości passLine.
        */
    void newUser(QString newUser, QString pass);
 
 protected:
    QLineEdit* m_passVerifyLine;
    QWidget* m_verifyWidget;
};


class LoginScreen : public QMainWindow {
    Q_OBJECT
 public: 
    LoginScreen();

 public slots:
    void showLoginPanel();
    void showRegisterPanel();
	void logout();
    void addUser(QString userName, QString password);
    void login(QString userName, QString password);
    bool eventFilter(QObject* o, QEvent* e);
 private:
    void createActions();

    QAction* createAction(QString name, QString text);
    User* m_User;
    QAction* m_Login;
    QAction* m_Register;
    QAction* m_Logout;
    
    LoginPanel* m_Panel;
    LoginPanel* m_LoginPanel;
    RegisterPanel* m_RegisterPanel;
    QStackedWidget* m_CentralWidget;
    PasswordManager* m_PasswordManager;
};

#endif        //  #ifndef LOGIN_H

