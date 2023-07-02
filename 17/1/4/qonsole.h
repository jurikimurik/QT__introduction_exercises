#ifndef QONSOLE_H
#define QONSOLE_H

#include <QLineEdit>
#include <QMainWindow>
#include <QProcess>
#include <QTextEdit>

class Qonsole : public QMainWindow
{
    Q_OBJECT
public:
    explicit Qonsole(QWidget *parent = nullptr);

public slots:
    void execute();
    void showOutput();
    bool eventFilter(QObject *watched, QEvent *event);

protected:
    void updateCursor();

private:
    QString m_UserInput;
    QTextEdit* m_Logw;
    QLineEdit* m_InputArea;
    QProcess* m_Shell;
};

#endif // QONSOLE_H
