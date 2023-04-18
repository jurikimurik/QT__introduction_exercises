#include "card.h"
#include "cardtable.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

//start

CardTable::CardTable(QWidget* parent)
: QWidget(parent) {

    QHBoxLayout* row = new QHBoxLayout();       /* Pierwszy wiersz. */
    row->addWidget(new Card("ah"));             /* Układ sam poprawnie ustawi rodziców, my nie musimy tego robić. */
    row->addWidget(new Card("qd"));
    row->addWidget(new Card("ks"));
    row->addWidget(new Card("8c"));

    QVBoxLayout* rows = new QVBoxLayout();      /* Rozmieść wiersze pionowo. */
    rows->addLayout(row);                       /* Zagnieźdź wiersz w układzie pionowym.  */

    row = new QHBoxLayout();                    /* Drugi wiersz. */
    row->addWidget(new Card("qs"));
    row->addWidget(new Card("js"));
    row->addWidget(new Card("td"));
    rows->addLayout(row);                       /* Znów zagnieżdżamy. */

    QVBoxLayout* buttons = new QVBoxLayout();   /* Kolumna na przyciski. */
	buttons->addWidget(new QPushButton("Rozdaj"));
    buttons->addWidget(new QPushButton("Potasuj"));


    QHBoxLayout* cols = new QHBoxLayout();      /* Połączmy wszystko.  */
    setLayout(cols);                            /* Najwyższy układ (korzeń) tego widżetu. */
    cols->addLayout(rows);                      /* Dodaj oba wiersze kart jako kolumnę. */
    cols->addLayout(buttons);                   /* Dodaj kolumnę przycisków jako kolejną kolumnę. */
}
//end












