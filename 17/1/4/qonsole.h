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
    ~Qonsole();

public slots:
    void execute();
    void showOutput();
    bool eventFilter(QObject *watched, QEvent *event);

protected:
    void updateCursor();

private:
    QTabWidget* m_tabWidget;

    QVector<QString> m_UserInputs;
    QVector<QTextEdit*> m_Logws;
    //QLineEdit* m_InputArea;
    QVector<QProcess*> m_Shells;
    int getCurrentTabIndex();
};

#endif // QONSOLE_H
