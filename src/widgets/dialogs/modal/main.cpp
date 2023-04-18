//start
#include <QtWidgets>
int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    QProgressDialog nonModal;
    nonModal.setWindowTitle("Niemodalne okno-rodzic ");
    nonModal.show();   /* Sterowanie natychmiast wraca do funkcji main(). */
    nonModal.connect(&nonModal, SIGNAL(finished()), 
            &app, SLOT(quit()));    /* Warunek zakończenia. */
 //end
    QProgressDialog *nonModal2 = new QProgressDialog(&nonModal);
    nonModal2->setWindowTitle("Niemodalne okno-dziecko");
    QProgressDialog nonModal3;
    nonModal3.setWindowTitle("Niemodalne okno dialogowe 3 bez rodzica");
    nonModal.resize(640, 480);
    nonModal2->resize(320, 200);
    nonModal3.resize(320, 200);
    nonModal2->show();
    nonModal3.show();
//start
fileDialog.exec();    /* Podobnie jak przy wejściu do pętli zdarzeń: wyjście nastąpi po zamknięciu okna. */
    QMessageBox::question(0, QObject::tr("Modalne okno bez rodzica "),
            QObject::tr("Czy możesz teraz prowadzić interakcję z innymi oknami?"), 
            QMessageBox::Yes | QMessageBox::No);
    return app.exec();       /* Wyjście po zamknięciu nonModal. */
}
//end
