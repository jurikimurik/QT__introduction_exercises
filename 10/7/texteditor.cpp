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
    setWindowTitle(m_FileName + "[NOT SAVED]");
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
}

void TextEditor::saveFile()
{
    qDebug() << "TextEditor::saveFile()";
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






