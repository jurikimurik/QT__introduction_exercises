#include "textfileexplorer.h"
#include "ui_textfileexplorer.h"

#include <QDebug>

TextFileExplorer::TextFileExplorer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextFileExplorer)
{
    ui->setupUi(this);
    m_PasekWyszukiwania = ui->searchLayout->findChild<QLineEdit*>("searchTextEdit");
    m_Wyszukiwarka = ui->textEdit;
    m_StatusLabel = ui->statusLabel;

    readSettings();
}

TextFileExplorer::~TextFileExplorer()
{
    delete ui;
}

void TextFileExplorer::onOpenButtonClicked()
{
    qDebug() << "TextFileExplorer::onOpenButtonClicked()";
    openFile();
}

void TextFileExplorer::onCloseButtonClicked()
{
    qDebug() << "TextFileExplorer::onCloseButtonClicked()";
    closeFile();
}

void TextFileExplorer::onExitButtonClicked()
{
    qDebug() << "TextFileExplorer::onExitButtonClicked()";
    close();
}

void TextFileExplorer::onPreviousButtonClicked()
{
    qDebug() << "TextFileExplorer::onPreviousButtonClicked()";
    previous();

}

void TextFileExplorer::onNextButtonClicked()
{
    qDebug() << "TextFileExplorer::onNextButtonClicked()";
    next();
}

void TextFileExplorer::onClearButtonClicked()
{
    qDebug() << "TextFileExplorer::onClearButtonClicked()";
    clear();
}

void TextFileExplorer::openFile()
{
    qDebug() << "TextEditor::openFile()";
    QString m_FileName = QFileDialog::getOpenFileName(this, "Otworz plik", "", "Text files (*.txt)");
    // BRAK PLIKU
    if(m_FileName.size() == 0) {
        m_FileName = "NowyPlik.txt";
        return;
    }

    m_Plik.setFileName(m_FileName);
    if(!m_Plik.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "NIE UDALO SIE OTWORZYC!";
        return;
    }

    ui->textEdit->setText(QString(m_Plik.readAll()));
}

void TextFileExplorer::openFile(QFile* plik)
{
    m_Plik.setFileName(plik->fileName());
    if(!m_Plik.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "NIE UDALO SIE OTWORZYC!";
        return;
    }

    ui->textEdit->setText(QString(m_Plik.readAll()));
}

void TextFileExplorer::closeFile()
{
    m_Wyszukiwarka->setText("");
    m_Plik.close();
}

void TextFileExplorer::closeEvent(QCloseEvent *event)
{
    qDebug() << "TextFileExplorer::closeEvent(QCloseEvent)";
    int odp = QMessageBox::question(this, "Zapis", "Czy chcesz zapisac stan okna?", "Tak", "Nie", QString(), 0, 1);
    if(odp == 0)
        saveSettings();
    event->accept();
}

void TextFileExplorer::previous()
{
    //USTAWIAMY FLAGE WYSZUKIWANIE DO PRZODU
    if(!m_Flagi.testFlag(QTextDocument::FindBackward))
        m_Flagi |= QTextDocument::FindBackward;
    search();
}

void TextFileExplorer::next()
{
    //ANULUJEMY, JEZELI USTAWIONY JEST NA WYSZUKIWANIE DO PRZODU
    if(m_Flagi.testFlag(QTextDocument::FindBackward))
        m_Flagi &= ~QTextDocument::FindBackward;
    search();
}

void TextFileExplorer::clear()
{
    m_PasekWyszukiwania->setText("");
}

void TextFileExplorer::search()
{
    QString searchWord = m_PasekWyszukiwania->text();
    bool czyZnaleziono = m_Wyszukiwarka->find(searchWord, m_Flagi);
    if (czyZnaleziono) {
        m_Wyszukiwarka->setFocus();
    }
    setStatus(czyZnaleziono);
}

void TextFileExplorer::setStatus(bool isGood)
{
    if(isGood) {

        m_StatusLabel->setStyleSheet("QLabel { color: green; }");
        m_StatusLabel->setText("Odnaleziono");
    } else {
        m_StatusLabel->setStyleSheet("QLabel { color: red; }");
        m_StatusLabel->setText("Brak wystapien.");
    }


}

void TextFileExplorer::saveSettings()
{
    qDebug() << "TextFileExplorer::saveSettings()";
    QSettings settings;
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("state", saveState());
    settings.setValue("file", m_Plik.fileName());
    settings.setValue("word", m_PasekWyszukiwania->text());
    settings.setValue("flagi", m_Flagi.toInt());
}

void TextFileExplorer::readSettings()
{
    qDebug() << "TextFileExplorer::readSettings()";
    QSettings settings;
    QPoint pos = settings.value("pos", QPoint(500, 500)).toPoint();
    QSize size = settings.value("size", QSize(700, 550)).toSize();
    QByteArray state = settings.value("state", QByteArray()).toByteArray();
    QString filename = settings.value("file", QString("")).toString();
    QString searchWord = settings.value("word", QString("")).toString();
    QTextDocument::FindFlags flagi =
        QTextDocument::FindFlags::fromInt(settings.value("flagi").toInt());

    m_Flagi = flagi;
    m_PasekWyszukiwania->setText(searchWord);
    m_Plik.setFileName(filename);
    restoreState(state);
    resize(size);
    move(pos);

    //Ustawiamy grafikę
    if(m_Plik.fileName().size() != 0)
        openFile(&m_Plik);
    if(m_Flagi.testFlag(QTextDocument::FindCaseSensitively))
        ui->searchLayout->findChild<QCheckBox*>("caseCheckBox")->setChecked(true);
    if(m_Flagi.testFlag(QTextDocument::FindWholeWords))
        ui->searchLayout->findChild<QCheckBox*>("wholeCheckBox")->setChecked(true);
}


void TextFileExplorer::on_caseCheckBox_stateChanged(int arg1)
{
    qDebug() << "TextFileExplorer::on_caseCheckBox_stateChanged(" << arg1 << ")";
    if(arg1)
        m_Flagi |= QTextDocument::FindCaseSensitively;
    else
        m_Flagi &= ~QTextDocument::FindCaseSensitively;
}


void TextFileExplorer::on_wholeCheckBox_stateChanged(int arg1)
{
    qDebug() << "TextFileExplorer::on_wholeCheckBox_stateChanged(" << arg1 << ")";
    if(arg1)
        m_Flagi |= QTextDocument::FindWholeWords;
    else
        m_Flagi &= ~QTextDocument::FindWholeWords;
}

