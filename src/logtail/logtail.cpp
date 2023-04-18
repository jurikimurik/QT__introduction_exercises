#include "logtail.h"
#include <QtWidgets>

//start id=constructor
LogTail::LogTail(QString fn) {
    connect (this, SIGNAL(readyReadStandardOutput()), 
        this, SLOT(logOutput()));       /* Wywołaj ten slot, gdy pojawią się gotowe dane wejściowe.*/
    QStringList argv;
     
    argv << "-f" << fn;                 /* tail -f nazwapliku */ 
    start("tail", argv);                /* Wyjście z funkcji następuje od razu. Od momentu jej wywołania do aktualnie działającego procesu podłączony jest proces potomny.
                                           Po zatrzymaniu aktualnego procesu zatrzymany zostanie także potomek. */
}
LogTail::~LogTail() {
    terminate();                        /* Próba zakończenia aktualnie uruchomionego procesu. */
}
//end

//start id=logOutput
// wynik wysyłany na stdout
void LogTail::logOutput() {             /* Slot wywoływany za każdym razem, gdy pojawią się dane wejściowe do odczytu. */
    QByteArray bytes = readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");
    foreach (QString line, lines) {
        emit logString(line); 
    }
}
//end
//start id=main
int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    QStringList al = app.arguments(); 
    QTextEdit textEdit;
    textEdit.setWindowTitle("Debug");
    textEdit.setWindowTitle("logtail demo");
    QString filename;
    if (al.size() > 1) filename = al[1];
    LogTail tail(filename);             /* Stwórz obiekt i uruchom proces. */
    tail.connect (&tail, SIGNAL(logString(const QString&)),
        &textEdit, SLOT(append(const QString&)));
    textEdit.show();
    return app.exec();
}
//end

