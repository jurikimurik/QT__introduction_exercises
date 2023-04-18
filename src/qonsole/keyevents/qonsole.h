#ifndef QONSOLE_H
#define QONSOLE_H

#include <QMainWindow>
class QProcess;
#include <QTextEdit> 
/** Qonsole 
    Przykład użycia QProcess i filtrów zdarzeń
    Autor: S. Alan Ezust
*/
//start
class Qonsole : public QMainWindow {
    Q_OBJECT
 public:
    Qonsole();
 public slots:
    void execute();
    void showOutput();
    bool eventFilter(QObject *o, QEvent *e)  ;
 protected:
    void updateCursor();
 private:
    QString m_UserInput;
    QTextEdit* m_Logw;
    QProcess* m_Shell;
};
//end
#endif

