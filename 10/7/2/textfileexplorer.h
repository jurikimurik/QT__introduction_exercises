#ifndef TEXTFILEEXPLORER_H
#define TEXTFILEEXPLORER_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QCloseEvent>
#include <QLineEdit>
#include <QTextEdit>
#include <QMessageBox>
#include <QSettings>
#include <QCheckBox>

namespace Ui {
class TextFileExplorer;
}

class TextFileExplorer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextFileExplorer(QWidget *parent = nullptr);
    ~TextFileExplorer();

private slots:
    void onOpenButtonClicked();
    void onCloseButtonClicked();
    void onExitButtonClicked();
    void onPreviousButtonClicked();
    void onNextButtonClicked();
    void onClearButtonClicked();

    void on_caseCheckBox_stateChanged(int arg1);
    void on_wholeCheckBox_stateChanged(int arg1);

private:
    void openFile();
    void openFile(QFile* plik);
    void closeFile();
    void closeEvent(QCloseEvent *event);
    void previous();
    void next();
    void clear();
    void search();
    void setStatus(bool isGood);

    void saveSettings();
    void readSettings();
private:
    Ui::TextFileExplorer *ui;

    QFile m_Plik;
    QLineEdit* m_PasekWyszukiwania;
    QTextEdit* m_Wyszukiwarka;
    QTextDocument::FindFlags m_Flagi;
    QLabel* m_StatusLabel;
};

#endif // TEXTFILEEXPLORER_H
