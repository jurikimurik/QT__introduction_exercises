#include "qonsole.h"

#include <QDockWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QString>
#include <QInputDialog>

Qonsole::Qonsole(QWidget *parent)
    : QMainWindow{parent}
{
    int count = QInputDialog::getInt(this, "Number Of Windows", "Input number of windows: ", 0, 1);
    m_tabWidget = new QTabWidget(this);

    m_UserInputs.resize(count);

    for(int i = 0; i < count; ++i) {
        QTextEdit* Logw = new QTextEdit();
        Logw->installEventFilter(this);
        Logw->setLineWrapMode(QTextEdit::WidgetWidth);
        m_Logws.push_back(Logw);

        m_tabWidget->addTab(Logw, "Tab " + QString::number(i));
        QProcess* shell = new QProcess(this);
        shell->setProcessChannelMode(QProcess::MergedChannels);
        connect(shell, &QProcess::readyReadStandardOutput, this, &Qonsole::showOutput);

# ifdef Q_OS_WIN
        shell->start("cmd", QStringList(), QIODevice::ReadWrite);
#else
        shell->start("bash", QStringList("-i"), QIODevice::ReadWrite);
#endif

        m_Shells.push_back(shell);
    }

    //m_Logw->setReadOnly(true);
    setCentralWidget(m_tabWidget);
    /*m_InputArea = new QLineEdit();
    QDockWidget* qdw = new QDockWidget("Tu wpisuj polecenia");
    qdw->setWidget(m_InputArea);
    addDockWidget(Qt::BottomDockWidgetArea, qdw);
    connect(m_InputArea, &QLineEdit::returnPressed, this, &Qonsole::execute);*/
}

Qonsole::~Qonsole()
{
    for(QProcess* process : m_Shells)
    {
        process->terminate();
    }
}

void Qonsole::execute()
{
    /*QString cmdStr = m_InputArea->text() + "\n";
    m_InputArea->setText("");
    m_Logw->append(cmdStr);
    QByteArray bytes = cmdStr.toUtf8();
    m_Shell->write(bytes);*/

    int index = getCurrentTabIndex();

    QByteArray bytes = m_UserInputs[index].toUtf8();
    m_Shells[index]->write(bytes);
    m_UserInputs[index] = "";
}

void Qonsole::showOutput()
{

    for(int i = 0; i < m_Shells.size(); ++i)
    {
        QProcess* m_Shell = m_Shells[i];
        QTextEdit* m_Logw = m_Logws[i];

        QByteArray bytes = m_Shell->readAllStandardOutput();
        QStringList lines = QString(bytes).split("\n");
        for(QString line : lines)
        {
            if(!line.isEmpty())
                m_Logw->append(line.toLatin1());
        }
    }




}

bool Qonsole::eventFilter(QObject *watched, QEvent *event)
{
    int index = getCurrentTabIndex();
    if(index == -1)
        return true;

    QTextEdit* m_Logw = m_Logws[index];

    if(event->type() == QEvent::KeyPress) {
        QKeyEvent* k = static_cast<QKeyEvent*>(event);
        int key = k->key();
        QString str = k->text();
        m_UserInputs[index].append(str);
        updateCursor();
        if((key == Qt::Key_Return) || (key == Qt::Key_Enter)) {
#ifdef Q_WS_WIN
            m_UserInput.append(QChar(0x000A));
#endif
            execute();
            return true;
        } else if (key == Qt::Key_Backspace) {
            if( m_UserInputs[index].size() > 0)
            {
                QString text = m_Logw->toPlainText();
                text.chop(1);
                m_Logw->setText(text);
            }
            m_UserInputs[index].chop(1);
            updateCursor();
            return true;
        } else {
            m_Logw->insertPlainText(str);
            return true;
        }
    }
    return false;
}

int Qonsole::getCurrentTabIndex()
{
    return m_tabWidget->currentIndex();
}

void Qonsole::updateCursor()
{
    int index = getCurrentTabIndex();

    QTextCursor cur = m_Logws[index]->textCursor();
    cur.movePosition(QTextCursor::End);
    m_Logws[index]->setTextCursor(cur);
}


