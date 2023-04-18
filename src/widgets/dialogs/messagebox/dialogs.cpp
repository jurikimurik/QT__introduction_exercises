//start
#include "dialogs.h"
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QAction>
#include <QDebug>
#include <QApplication>

Dialogs::Dialogs() {
    QWidget::setWindowTitle( "Gullap Poll" ); /* Prefiksy ClassName::, których używamy w poniższych metodach,
	nie są obowiązkowe, ponieważ metody są wywoływane na "this".
	Podajemy nazwę klasy tylko po to, by Czytelnik
	wiedział, z której klasy odziedziczona została dana metoda. */
    QWidget::move(300, 300);
//end
//start id="menu"    
	/* Umieść menu na pasku */
    QMenu* menu = new QMenu(tr("&Pytania"), this);

    QMainWindow::menuBar()->addMenu(menu);

    /* Kilka opcji w menu */
    menu->addAction(tr("&Zadaj pytanie"),
                    this, SLOT(askQuestion()), tr("Alt+Z"));
    menu->addAction(tr("Zadaj &głupie pytanie"),
                    this, SLOT(askDumbQuestion()), tr("Alt+G"));
}

//end
//start id="messagebox"
void Dialogs::askQuestion() {
    bool done=false;
    QString q1(tr("Kto był premierem Kanady w roku 1847?")),
            a0("John A. Macdonald"), a1("Alexander Mackenzie"),
            a2("Sir Wilfred Laurier");
    while (!done) {
        int ans = QMessageBox::
                  question( this, /* Okno dialogowe jest modalne względem rodzica. */
                  tr("Trudne pytanie"),
                  q1, a0, a1, a2, 
                  0,  /* wartość domyślna */
                  -1  /* wartość wysyłana po "esc" lub "windowclose" */ ) ;
        if (ans < 0) return; /* Jeśli zamknięto okno, to QButton nie został wciśnięty. */                                       
        switch( ans ) {
        case 0:
            answer = a0;
            break;
        case 1:
            answer = a1;
            break;
        case 2:
            answer = a2;
            break;
        }
        QString q2(QString(tr("Twoja odpowiedź: %1."
                           " Niepoprawna.\n Spróbujesz jeszcze raz?"))
                           .arg(answer));
        int again = QMessageBox::
                    question(this, tr("Twój wynik"), q2,
                    tr("Nie"), tr("Tak"), tr("Poddaję się - jaka jest odpowiedź?"));
                                          
        if ( again <1 ) {
            return;
        }
        if (again == 2) {
            QMessageBox::
            information(this, "Ha Ha!",
                        tr("Do roku 1867 nie było żadnych premierów!"),
                        "Grrrrr.....");
            return;
        }
    }
}

//end

void Dialogs::askDumbQuestion() {

    switch( QMessageBox::
            question( this, tr("Głupie pytanie"),
                     tr("Jakim zwierzęciem politycznym jesteś?"),
                     tr("osioł"), tr("słoń"),tr("pingwin"),
                     1, -1 ) ) {
    case 0:
        answer = tr("<i>Uwielbiamy publiczną służbę zdrowia!</i>");
        QMessageBox::
        information(this, tr("Nieprzydatna informacja"), answer,
                    QMessageBox::Ignore, QMessageBox::Ok,
                    QMessageBox::NoButton);
        return;
        break;
    case 1:
        answer = tr("Przecz z ewolucją!");
        QMessageBox::
        warning(this, tr("Co nauka kiedykolwiek zrobiła dla mnie?"), answer,
                QMessageBox::Ignore, QMessageBox::Cancel, 
                QMessageBox::YesAll);

        return;
        break;
    case 2:
        answer = tr("<b>Niech żyje Linux!!</b>!");
        QMessageBox::
        critical(this, tr("komunikat krytyczny"), answer, 
                 QMessageBox::Abort, QMessageBox::Retry, 
                 QMessageBox::Ignore);
        return;
        break;
    }
}

//start

int main( int argc, char ** argv ) {
    QApplication a( argc, argv );
    Dialogs* awd = new Dialogs();
    awd->show();
    a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
    return a.exec();
}

