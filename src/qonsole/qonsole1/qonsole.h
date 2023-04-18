#ifndef QONSOLE_H
#define QONSOLE_H

 

#include <QMainWindow>
class QLineEdit;
class QProcess;
class QTextEdit;
/**
  Prosta, przykładowa aplikacja pokazująca, jak korzystać z QProcess
  w połączeniu z sygnałami i slotami, zapewniającymi dwukierunkową komunikację.
  */
//start
class Qonsole : public QMainWindow {
    Q_OBJECT
 public:
    Qonsole();
 public slots:
    void execute();
    void showOutput();
 private:
    QTextEdit* m_Logw;
    QLineEdit* m_InputArea;
    QProcess* m_Shell;
};
//end
#endif

