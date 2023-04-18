#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QAction>
#include <QDebug>
#include <QApplication>
#include <QToolBar>
#include <QMessageBox>
#include <QActionGroup>
#include "study.h"

//start id=main
int main( int argc, char** argv ) {
    QApplication app( argc, argv );
    Study study;
    study.show();
    return app.exec();
}
//end
//start id=addchoice

// Funkcja wytwórcza (fabryka) produkująca akcje QAction inicjalizowane w ujednolicony sposób
QAction* Study::addChoice(QString name, QString text) {
    QAction* retval = new QAction(text, this);
    retval->setObjectName(name);
    retval->setEnabled(false);
    retval->setCheckable(true);
    actionGroup->addAction(retval); /* Dodaj każdą akcję do QActionGroup, 
	dzięki czemu potrzebny będzie tylko jeden sygnał podłączony 
	do jednego slotu. */
    return retval;
}
//end
//start id=study
Study::Study(QWidget* parent) : QMainWindow(parent) {
    actionGroup = new QActionGroup(this);
    actionGroup->setExclusive(false);
    statusBar();
	
    QWidget::setWindowTitle( "zostać jedi chcesz?");   /* Niektóre z użytych tu prefiksów NazwaKlasy:: nie są wymagane, 
		ponieważ funkcje można wywołać na this. Nazw klas można użyć, by wywołać wersję funkcji zdefiniowaną w konkretnej 
		nadklasie lub by pokazać czytelnikowi kodu, którą wersję wywołujemy. */

    QMenu* useMenu = new QMenu("&Użyj", this);
    QMenu* studyMenu = new QMenu("&Studiuj", this);
    QMenu* fightMenu = new QMenu("&Walcz", this);

    useTheForce = addChoice("useTheForce", "Użyj &Mocy");
    useTheForce->setStatusTip("To początek podróży...");
    useTheForce->setEnabled(true);
    useMenu->addAction(useTheForce);   /* Akcja jest już w QActionGroup, ale dodajemy ją także do QMenu.  */
//end
    useTheDarkSide = addChoice("useTheDarkSide", "Użyj ciemnej strony Mocy");
    useMenu->addAction(useTheDarkSide);
    useTheDarkSide->setStatusTip("Nie da się tego uniknąć, jak jabłka w Edenie...");
//start id=study
    studyWithObiWan = addChoice("studyWithObiWan", "&Ucz się u Obi-Wana ");
    studyMenu->addAction(studyWithObiWan);
    studyWithObiWan->setStatusTip("Z pewnością otworzy przed Tobą "
                                   "wiele drzwi...");
    fightObiWan = addChoice("fightObiWan", "&Walcz z Obi-Wanem");
    fightMenu->addAction(fightObiWan);
    fightObiWan->setStatusTip("W ten sposób z pewnością "
                               "nauczysz się od niego wielu sztuczek!");
//end
    studyWithYoda = addChoice("studyWithYoda", "Ucz się u &Yody");
    studyMenu->addAction(studyWithYoda);
    studyWithYoda->setStatusTip("Jest mistrzem, dlaczego się wahasz?");

    fightYoda = addChoice("fightYoda", "Walcz z Y&odą");
    fightMenu->addAction(fightYoda);
    fightYoda->setStatusTip("Zwariowałeś?");

    fightDarthVader = addChoice("fightDarthVader", "Walcz z Darthem &Vaderem");
    fightMenu->addAction(fightDarthVader);

    fightEmperor = addChoice("fightEmperor", "Walcz z Imperator&em");
    fightMenu->addAction(fightEmperor);

    studyWithEmperor = addChoice("studyWithEmperor", "Ucz się u Imperato&ra");
    studyMenu->addAction(studyWithEmperor);
//start id=study
	QMainWindow::menuBar()->addMenu(useMenu);
    QMainWindow::menuBar()->addMenu(studyMenu);
    QMainWindow::menuBar()->addMenu(fightMenu);

    toolbar = new QToolBar("Pasek wyboru", this);    /* W ten sposób uzyskujemy widoczne przyciski w dokowanym 
		(przyłączanym) widżecie dla każdej z QAction. */ 
    toolbar->addActions(actionGroup->actions());

    QMainWindow::addToolBar(Qt::LeftToolBarArea, toolbar);


    QObject::connect(actionGroup, SIGNAL(triggered(QAction*)),
            this, SLOT(actionEvent(QAction*)));      /* Zamiast podłączać sygnał każdej z akcji, 
		łączymy się jedynie z zawierającą je wszystkie grupą ActionGroup. */

    QWidget::move(300, 300);
    QWidget::resize(300, 300);
}

//end

//start id=actionevent
void Study::actionEvent(QAction* act) {
   QString name = act->objectName();
   QString msg = QString();

   if (act == useTheForce ) { // użyj Mocy
       studyWithObiWan->setEnabled(true); // ucz się u Obi-Wana
       fightObiWan->setEnabled(true); // walcz z Obi-Wanem
       useTheDarkSide->setEnabled(true); // użyj ciemnej strony Mocy
   }
   if (act == useTheDarkSide) { // użyj ciemnej strony Mocy
       studyWithYoda->setEnabled(false); // ucz się u Yody
       fightYoda->setEnabled(true); // walcz z Yodą
       studyWithEmperor->setEnabled(true); // ucz się u Imperatora
       fightEmperor->setEnabled(true); // walcz z Imperatorem
       fightDarthVader->setEnabled(true); // walcz z Darthem Vaderem
   }
   if (act == studyWithObiWan) { // ucz się u Obi-Wana
       fightObiWan->setEnabled(true); // walcz z Obi-Wanem
       fightDarthVader->setEnabled(true); // walcz z Darthem Vaderem
       studyWithYoda->setEnabled(true); // ucz się u Yody
   }

//end

   if (act == studyWithYoda) {
       fightDarthVader->setEnabled(true);
       fightEmperor->setEnabled(true);
   }
   if (act == fightYoda) {
       msg = "Przegrałeś.";
       act->setChecked(false);
       studyWithYoda->setEnabled(false);
   }
//start id=actionevent
   if (act == fightObiWan ) { 
       if (studyWithEmperor->isChecked()) { 
            msg = "Wygrałeś!";
       }
       else {
           msg = "Przegrałeś.";
           act->setChecked(false);
           studyWithYoda->setEnabled(false);
       }
   }

//end
   if (act == fightDarthVader ) {
       if (studyWithYoda->isChecked() == false) {
           msg = "Pożegnaj się ze swoją dłonią! Ciach!";
           act->setChecked(false);
       }
       else {
           msg = "Dokopałeś Vaderowi!";
           studyWithEmperor->setEnabled(false);
           studyWithYoda->setEnabled(true);
       }
   }
   if (act == studyWithEmperor) {
       studyWithEmperor->setChecked(true);
   }
   if (act == fightEmperor ) {
       if (fightObiWan->isChecked()) {
           msg = "Pokonałeś złego Imperatora!";
       }
       else {
           msg = "Usmażyłeś się na skwarek!";
           studyWithEmperor->setEnabled(false);
           fightEmperor->setChecked(false);
       }
   }
//start id=actionevent
   if (msg != QString()) {
      QMessageBox::information(this, "Wynik", msg, "ok");
   }
}
//end

