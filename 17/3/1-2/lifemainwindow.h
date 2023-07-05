#ifndef LIFEMAINWINDOW_H
#define LIFEMAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTime>
#include <QRect>
#include <QImage>
#include "lifeslice.h"
#include <random>

class LifeWidget;
namespace Ui {
    class LifeMainWindow;
}

/** Przykład z grą w życie rozproszony pomiędzy
    wątki przy użyciu funkcji mapReduce z QtConcurrent.
*/ 
class LifeMainWindow : public QMainWindow
{
    Q_OBJECT

public:  
    explicit LifeMainWindow(QWidget *parent = 0);
    ~LifeMainWindow();
    void closeEvent(QCloseEvent *);

private:
    Ui::LifeMainWindow *ui;
    LifeWidget* m_lifeWidget;
    QImage m_current;
    int m_numGenerations;
    QElapsedTimer m_timer;
    bool m_running;
    std::default_random_engine m_engine;
    std::uniform_int_distribution<int> m_distribution;


private slots:
    void on_actionAbout_Qt_triggered();
    void on_actionAbout_triggered();
    void on_threadSpinBox_valueChanged(int );
    void on_actionQuit_triggered();
    void on_actionClear_triggered();
    void on_actionStartStop_triggered(bool checked);
    void on_actionPopulate_Randomly_triggered();
    void calculate();
};

#endif // LIFEMAINWINDOW_H
