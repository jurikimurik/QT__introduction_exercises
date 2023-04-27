#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QCloseEvent>
#include <QMessageBox>

namespace Ui {
class TextEditor;
}

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = nullptr);
    ~TextEditor();




private slots:
    void on_textEdit_textChanged();
    void onOpenFileButtonClicked();
    void onSaveFileButtonClicked();
    void onAboutAppButtonClicked();
    void onAboutQtButtonClicked();
    void onExitButtonClicked();

private:
    void openFile();
    void saveFile();
    void closeEvent(QCloseEvent *event);
    void showAboutQT();
    void showAboutApp();

private:
    Ui::TextEditor *ui;

    bool m_Saved;
    QString m_FileName;
};

#endif // TEXTEDITOR_H
