#ifndef LogTail_H
#define LogTail_H

//start
#include <QObject>
#include <QProcess>

/**
    Prosty przykład korzystający z QProcess i tail -f jako polecenia zewnętrznego. 
    Uruchamia proces i podłącza jego sygnały wyjściowe do Loggera.
    */
class LogTail : public QProcess {
    Q_OBJECT
  public:
    LogTail(QString fn = QString());
    ~LogTail();
  signals:
    void logString(const QString &str);
    
  public slots:
    void logOutput();
};
//end

#endif

