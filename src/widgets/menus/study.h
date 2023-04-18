#ifndef STUDY_H
#define STUDY_H

#include <QMainWindow>
class QAction;
class QActionGroup;

/**
  Demo QAction i QActionGroup
  S. Alan Ezust (alan dot ezust at gmail dot com )
  */
//start
class Study : public QMainWindow {
    Q_OBJECT
 public:
    explicit Study(QWidget* parent=0);
 public slots:
    void actionEvent(QAction* act);
 private:
    QActionGroup* actionGroup;  /* Do przechwytywania sygnałów. */
    QToolBar* toolbar;          /* Do wyświetlania akcji jako przycisków. */
	
    QAction* useTheForce;
    QAction* useTheDarkSide;
    QAction* studyWithObiWan;
    QAction* studyWithYoda;
    QAction* studyWithEmperor;
    QAction* fightYoda;
    QAction* fightDarthVader;
    QAction* fightObiWan;
    QAction* fightEmperor;
protected:
    /**
       Dodaje do paska narzędzi nową akcję QAction i ją zwraca.
       */
    QAction* addChoice(QString name, QString text);

};
//end
#endif


