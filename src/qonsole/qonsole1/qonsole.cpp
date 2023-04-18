#include "qonsole.h"

#include <QTextEdit>
#include <QDockWidget>
#include <QLineEdit>
#include <QProcess>
#include <QByteArray>
//start id=constructor
Qonsole::Qonsole() {
   m_Logw = new QTextEdit();
   m_Logw->setReadOnly(true);
   setCentralWidget(m_Logw);
   m_InputArea = new  QLineEdit();
   QDockWidget* qdw = new QDockWidget("Tu wpisuj polecenia");
   qdw->setWidget(m_InputArea);
   addDockWidget(Qt::BottomDockWidgetArea, qdw);
   connect (m_InputArea, SIGNAL(returnPressed()),
			this, SLOT(execute()));

   m_Shell = new QProcess(this);
   m_Shell->setReadChannelMode(QProcess::MergedChannels);           /* Scalenie stdout i stderr. */
   connect (m_Shell, SIGNAL(readyReadStandardOutput()),
			 this, SLOT(showOutput()));
#ifdef Q_OS_WIN
   m_Shell->start("cmd", QStringList(), QIODevice::ReadWrite);
#else
   m_Shell->start("bash", QStringList("-i"), QIODevice::ReadWrite); /* Uruchomienie bash w trybie interaktywnym. */
#endif

}
//end

//start id=methods
void Qonsole::showOutput() {            /* Slot wywoływany za każdym razem, gdy gotowe są dane wejściowe. */
    QByteArray bytes = m_Shell->readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");
    foreach (QString line, lines) {
        m_Logw->append(line);
    }
}

void Qonsole::execute() {
    QString cmdStr = m_InputArea->text() + "\n";
    m_InputArea->setText("");
    m_Logw->append(cmdStr);
    QByteArray bytes = cmdStr.toUtf8(); /* Przekształcenie do kodowania UTF-8. */
    m_Shell->write(bytes);               /* Wyślij dane do strumienia stdin procesu potomnego Shell. */
}
//end
//start id=main
#include <QApplication>

int main(int argc, char* argv[]) {
   QApplication app(argc, argv);
   Qonsole qon;
   qon.show();
   return app.exec();
}
//end

