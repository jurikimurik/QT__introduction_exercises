#include "texteditor.h"
#include "ui_texteditor.h"

#include <QDebug>

TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditor),
    m_Saved(false)
{
    ui->setupUi(this);

    // OTWORZ PLIK
    openFile();
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::on_textEdit_textChanged()
{
    qDebug() << "TextEditor::on_textEdit_textChanged()";
    m_Saved = false;
    setWindowTitle(m_FileName.split("/").takeLast() + "[NOT SAVED]");
}

void TextEditor::onOpenFileButtonClicked()
{
    openFile();
}

void TextEditor::onSaveFileButtonClicked()
{
    saveFile();
}

void TextEditor::onAboutAppButtonClicked()
{
    showAboutApp();
}

void TextEditor::onAboutQtButtonClicked()
{
    showAboutQT();
}

void TextEditor::onExitButtonClicked()
{
    close();
}

void TextEditor::openFile()
{
    qDebug() << "TextEditor::openFile()";
    m_FileName = QFileDialog::getOpenFileName(this, "Otworz plik", "", "Text files (*.txt)");
    // BRAK PLIKU
    if(m_FileName.size() == 0)
        return;

    QFile plik(m_FileName);
    if(!plik.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "NIE UDALO SIE OTWORZYC!";
        return;
    }

    ui->textEdit->setText(QString(plik.readAll()));
    plik.close();
}

void TextEditor::saveFile()
{
    qDebug() << "TextEditor::saveFile()";
    QString saveFileName = QFileDialog::getSaveFileName(this, "Zapisz plik", "", "Text files (*.txt)");
    //BRAK ZAPISU
    if(saveFileName.size() == 0) {
        return;
    }

    QFile plik(saveFileName);
    if(!plik.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "NIE DA SIE ZAPISAC!";
        return;
    }

    plik.write(ui->textEdit->toPlainText().toUtf8());
    plik.close();

    m_Saved = true;
    setWindowTitle(m_FileName.split("/").takeLast());
}

void TextEditor::closeEvent(QCloseEvent *event)
{
    qDebug() << "TextEditor::closeEvent()";
    event->accept();
}

void TextEditor::showAboutQT()
{
    qDebug() << "TextEditor::showAboutQT()";
}

void TextEditor::showAboutApp()
{
    qDebug() << "TextEditor::showAboutApp()";
}






