#include <QApplication>
#include "ObjectBrowserModel.h"
#include <QDialog>
#include "ui_test.h"
#include <QTreeView>
#include <QDebug>
#include <QModelIndex>
#ifdef MODELTEST
#include "modeltest.h"
#endif

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    QDialog* dialog = new QDialog;
    Ui::Test* ui = new Ui::Test;
    ui->setupUi( dialog );
    dialog->show();

    ObjectBrowserModel* model = new ObjectBrowserModel(dialog);
#ifdef MODELTEST
    new ModelTest(model, dialog);
#endif
    QTreeView* view = new QTreeView;
    view->setModel( model );
    view->resize( 400, 600 );
    view->show();
/*
    // Pierwszy krok, czy otrzymasz prawdziwy indeks ze swojego modelu?
    QModelIndex top1 = model->index( 0,0, QModelIndex() );
    qDebug() << "Pierwsze dziecko najwyższego poziomu: " << top1 << top1.isValid();

    QModelIndex top2 = model->index( 1,0, QModelIndex() );
    qDebug() << "Drugie dziecko najwyższego poziomu: " << top2 << top2.isValid();

    // Czy Twoja funkcja data działa na indeksach najwyższego poziomu?
    qDebug() << "Nazwa klasy pierwszego dziecka najwyższego poziomu (QDialog|QTreeView)" << model->data( top1, Qt::DisplayRole );
    qDebug() << "Nazwa klasy drugiego dziecka najwyższego poziomu (QDialog|QTreeView)" << model->data( top2, Qt::DisplayRole );

    // Czy Twój model zwróci poprawny wynik dla ról niewyświetlanych?
    qDebug() << "Niech to będzie pusty indeks:" << model->data( top1, Qt::ForegroundRole );
    qDebug() << "Niech to będzie pusty indeks:" << model->data( top2, Qt::ForegroundRole );

    // Teraz sprawdźmy, czy potrafisz również obsługiwać podindeksy.
    QModelIndex sub1 = model->index( 0,0, top1 );
    qDebug() << "Pierwsze dziecko pierwszego najwyższego: " << sub1;

    QModelIndex sub2 = model->index( 1,0, top1 );
    qDebug() << "Drugie dziecko pierwszego najwyższego: " << sub2;

    // Czy Twoja funkcja data działa na tych indeksach?
    qDebug() << "Nazwa klasy pierwszego dziecka"  << model->data( sub1, Qt::DisplayRole );
    qDebug() << "Nazwa klasy drugiego dziecka" << model->data( sub2, Qt::DisplayRole );

    // Teraz sprawdźmy, czy poprawnie zaimplementowałeś funkcję parent
    qDebug() << "rodzic indeksu najwyższego poziomu (pownien być pusty): " << model->parent(top1);
    qDebug() << "rodzic pierwszego dziecka (powinien to być top)" << model->parent(sub1) << " == " << top1;
    qDebug() << "rodzic drugiego dziecka (powinien to być top)" << model->parent(sub2) << " == " << top1;

    // Spróbujmy przejść o poziom niżej.
    QModelIndex subsub1 = model->index( 0,0, sub1 );
    qDebug() << "Dziecko dziecka: " << subsub1;
    qDebug() << "nazwa klasy dziecka subsub: " << model->data( subsub1, Qt::DisplayRole );
    qDebug() << "rodzic dziecka subsub: " << model->parent( subsub1 ) << " == " << sub1;
*/


    return app.exec();
}
