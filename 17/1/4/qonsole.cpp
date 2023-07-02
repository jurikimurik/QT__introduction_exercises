#include "qonsole.h"

#include <QDockWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QString>

Qonsole::Qonsole(QWidget *parent)
    : QMainWindow{parent}
{
    m_Logw = new QTextEdit();
    //m_Logw->setReadOnly(true);
    setCentralWidget(m_Logw);
    /*m_InputArea = new QLineEdit();
    QDockWidget* qdw = new QDockWidget("Tu wpisuj polecenia");
    qdw->setWidget(m_InputArea);
    addDockWidget(Qt::BottomDockWidgetArea, qdw);
    connect(m_InputArea, &QLineEdit::returnPressed, this, &Qonsole::execute);*/

    m_Logw->installEventFilter(this);
    m_Logw->setLineWrapMode(QTextEdit::WidgetWidth);

    m_Shell = new QProcess(this);
    m_Shell->setProcessChannelMode(QProcess::MergedChannels);
    connect(m_Shell, &QProcess::readyReadStandardOutput, this, &Qonsole::showOutput);
# ifdef Q_OS_WIN
    m_Shell->start("cmd", QStringList(), QIODevice::ReadWrite);
#else
    m_Shell->start("bash", QStringList("-i"), QIODevice::ReadWrite);
#endif
}

void Qonsole::execute()
{
    /*QString cmdStr = m_InputArea->text() + "\n";
    m_InputArea->setText("");
    m_Logw->append(cmdStr);
    QByteArray bytes = cmdStr.toUtf8();
    m_Shell->write(bytes);*/

    QByteArray bytes = m_UserInput.toUtf8();
    m_Shell->write(bytes);
    m_UserInput = "";
}

void Qonsole::showOutput()
{
    QByteArray bytes = m_Shell->readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");
    for(QString line : lines)
    {
        m_Logw->append(line.toLatin1());
    }
}

bool Qonsole::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress) {
        QKeyEvent* k = static_cast<QKeyEvent*>(event);
        int key = k->key();
        QString str = k->text();
        m_UserInput.append(str);
        updateCursor();
        if((key == Qt::Key_Return) || (key == Qt::Key_Enter)) {
#ifdef Q_WS_WIN
            m_UserInput.append(QChar(0x000A));
#endif
            execute();
            return true;
        } else if (key == Qt::Key_Backspace) {
            if(m_UserInput.size() > 0)
            {
                QString text = m_Logw->toPlainText();
                text.chop(1);
                m_Logw->setText(text);
            }
            m_UserInput.chop(1);
            updateCursor();
            return true;
        } else {
            m_Logw->insertPlainText(str);
            return true;
        }
    }
    return false;
}

void Qonsole::updateCursor()
{
    QTextCursor cur = m_Logw->textCursor();
    cur.movePosition(QTextCursor::End);
    m_Logw->setTextCursor(cur);
}


