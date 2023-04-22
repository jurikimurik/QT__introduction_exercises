#ifndef KEYSEQUENCELABEL_H
#define KEYSEQUENCELABEL_H

#include <QMainWindow>
#include "ui_ksl.h"
#include <QList>
#include <QPair>
class QObjectBrowserAction;

class KeySequenceLabel : public Ui_KSL
{
    Q_OBJECT
public:
    explicit KeySequenceLabel(QWidget* parent = nullptr);
protected:
    void changeEvent(QEvent* e);
    void keyPressEvent(QKeyEvent *e);
    void leaveEvent(QEvent* e);
    void enterEvent(QEnterEvent* e);
    void paintEvent(QPaintEvent* e);
    void timerEvent(QTimerEvent* e);
    void updateUi();
private slots:
    void on_actionShow_ObjectBrowser_triggered(bool checked);
    void on_clearButton_clicked();
    void onactionQuit_triggered();
private:
    QObjectBrowserAction* m_browserAction;
};

#endif // KEYSEQUENCELABEL_H
