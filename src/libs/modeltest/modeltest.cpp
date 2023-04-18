/****************************************************************************
**
** Copyright (C) 2007 Trolltech ASA. All rights reserved.
**
** This file is part of the Qt Concurrent project on Trolltech Labs.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
** http://www.trolltech.com/products/qt/opensource.html
**
** If you are unsure which license is appropriate for your use, please
** review the following information:
** http://www.trolltech.com/products/qt/licensing.html or contact the
** sales department at sales@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include <QtGui/QtGui>

#include "modeltest.h"

Q_DECLARE_METATYPE(QModelIndex)

/*!
    Podłącz się do wszystkich sygnałów modelu. Po każdej zmianie ponownie wszystko sprawdź.
*/
ModelTest::ModelTest(QAbstractItemModel *_model, QObject *parent) : QObject(parent), model(_model), fetchingMore(false)
{
    Q_ASSERT(model);

    connect(model, SIGNAL(columnsAboutToBeInserted(const QModelIndex &, int, int)),
            this, SLOT(runAllTests()));
    connect(model, SIGNAL(columnsAboutToBeRemoved(const QModelIndex &, int, int)),
            this, SLOT(runAllTests()));
    connect(model, SIGNAL(columnsInserted(const QModelIndex &, int, int)),
            this, SLOT(runAllTests()));
    connect(model, SIGNAL(columnsRemoved(const QModelIndex &, int, int)),
            this, SLOT(runAllTests()));
    connect(model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)),
            this, SLOT(runAllTests()));
    connect(model, SIGNAL(headerDataChanged(Qt::Orientation, int, int)),
            this, SLOT(runAllTests()));
    connect(model, SIGNAL(layoutAboutToBeChanged ()), this, SLOT(runAllTests()));
    connect(model, SIGNAL(layoutChanged ()), this, SLOT(runAllTests()));
    connect(model, SIGNAL(modelReset ()), this, SLOT(runAllTests()));
    connect(model, SIGNAL(rowsAboutToBeInserted(const QModelIndex &, int, int)),
            this, SLOT(runAllTests()));
    connect(model, SIGNAL(rowsAboutToBeRemoved(const QModelIndex &, int, int)),
            this, SLOT(runAllTests()));
    connect(model, SIGNAL(rowsInserted(const QModelIndex &, int, int)),
            this, SLOT(runAllTests()));
    connect(model, SIGNAL(rowsRemoved(const QModelIndex &, int, int)),
            this, SLOT(runAllTests()));

    // Specjalne testy na wstawianie i wyjmowanie
    connect(model, SIGNAL(layoutAboutToBeChanged()),
            this, SLOT(layoutAboutToBeChanged()));
    connect(model, SIGNAL(layoutChanged()),
            this, SLOT(layoutChanged()));

    connect(model, SIGNAL(rowsAboutToBeInserted(const QModelIndex &, int, int)),
            this, SLOT(rowsAboutToBeInserted(const QModelIndex &, int, int)));
    connect(model, SIGNAL(rowsAboutToBeRemoved(const QModelIndex &, int, int)),
            this, SLOT(rowsAboutToBeRemoved(const QModelIndex &, int, int)));
    connect(model, SIGNAL(rowsInserted(const QModelIndex &, int, int)),
            this, SLOT(rowsInserted(const QModelIndex &, int, int)));
    connect(model, SIGNAL(rowsRemoved(const QModelIndex &, int, int)),
            this, SLOT(rowsRemoved(const QModelIndex &, int, int)));

    runAllTests();
}

void ModelTest::runAllTests()
{
    if (fetchingMore)
        return;
    nonDestructiveBasicTest();
    rowCount();
    columnCount();
    hasIndex();
    index();
    parent();
    data();
}

/*!
    nonDestructiveBasicTest próbuje wywołać pewną liczbę podstawowych funkcji (nie wszystkie)
	by upewnić się, że model nie prowadzi do natychmiastowego błędu pamięci podczas testowania 
	funkcji, które faktycznie coś robią.
*/
void ModelTest::nonDestructiveBasicTest()
{
    Q_ASSERT(model->buddy(QModelIndex()) == QModelIndex());
    model->canFetchMore(QModelIndex());
    Q_ASSERT(model->columnCount(QModelIndex()) >= 0);
    Q_ASSERT(model->data(QModelIndex()) == QVariant());
    fetchingMore = true;
    model->fetchMore(QModelIndex());
    fetchingMore = false;
    Qt::ItemFlags flags = model->flags(QModelIndex());
    Q_ASSERT(flags == Qt::ItemIsDropEnabled || flags == 0);
    model->hasChildren(QModelIndex());
    model->hasIndex(0, 0);
    model->headerData(0, Qt::Horizontal);
    model->index(0, 0);
    Q_ASSERT(model->index(-1, -1) == QModelIndex());
    model->itemData(QModelIndex());
    QVariant cache;
    model->match(QModelIndex(), -1, cache);
    model->mimeTypes();
    Q_ASSERT(model->parent(QModelIndex()) == QModelIndex());
    Q_ASSERT(model->rowCount() >= 0);
    QVariant variant;
    model->setData(QModelIndex(), variant, -1);
    model->setHeaderData(-1, Qt::Horizontal, QVariant());
    model->setHeaderData(0, Qt::Horizontal, QVariant());
    model->setHeaderData(999999, Qt::Horizontal, QVariant());
    QMap<int, QVariant> roles;
    model->sibling(0, 0, QModelIndex());
    model->span(QModelIndex());
    model->supportedDropActions();
}

/*!
    Implementacja QAbstractItemModel::rowCount() i hasChildren() na potrzeby testów

    Modele wypełniane dynamicznie nie są tu testowane w aż tak kompletny sposób.
 */
void ModelTest::rowCount()
{
    // sprawdź pierwszy wiersz
    QModelIndex topIndex = model->index(0, 0, QModelIndex());
    int rows = model->rowCount(topIndex);
    Q_ASSERT(rows >= 0);
    if (rows > 0)
        Q_ASSERT(model->hasChildren(topIndex) == true);

    QModelIndex secondLevelIndex = model->index(0, 0, topIndex);
    if (secondLevelIndex.isValid()) { // to nie jest najwyższy poziom
        // sprawdź numer wiersza, jeśli rodzic jest poprawny
        rows = model->rowCount(secondLevelIndex);
        Q_ASSERT(rows >= 0);
        if (rows > 0)
            Q_ASSERT(model->hasChildren(secondLevelIndex) == true);
    }

    // rowCount() jest testowana dokładniej w checkChildren(),
    // ale to wystarczy do wychwycenia poważnych błędów
}

/*!
    Implementacja QAbstractItemModel::columnCount() i hasChildren() na potrzeby testów
 */
void ModelTest::columnCount()
{
    // sprawdź pierwszy wiersz
    QModelIndex topIndex = model->index(0, 0, QModelIndex());
    Q_ASSERT(model->columnCount(topIndex) >= 0);

    // sprawdź numer wiersza, jeśli rodzic jest poprawny
    QModelIndex childIndex = model->index(0, 0, topIndex);
    if (childIndex.isValid())
        Q_ASSERT(model->columnCount(childIndex) >= 0);

    // columnCount() jest testowana dokładniej w checkChildren(),
    // ale to wystarczy do wychwycenia poważnych błędów
}

/*!  
	Implementacja QAbstractItemModel::hasIndex() na potrzeby testów
 */
void ModelTest::hasIndex()
{
    // Upewnij się, że niepoprawne wartości prowadzą do zwrócenia nieważnego indeksu
    Q_ASSERT(model->hasIndex(-2, -2) == false);
    Q_ASSERT(model->hasIndex(-2, 0) == false);
    Q_ASSERT(model->hasIndex(0, -2) == false);

    int rows = model->rowCount();
    int columns = model->columnCount();

    // sprawdzenie granic
    Q_ASSERT(model->hasIndex(rows, columns) == false);
    Q_ASSERT(model->hasIndex(rows + 1, columns + 1) == false);

    if (rows > 0)
        Q_ASSERT(model->hasIndex(0, 0) == true);

    // hasIndex() jest testowana dokładniej w checkChildren(),
    // ale to wystarczy do wychwycenia poważnych błędów
}

/*!
	Implementacja QAbstractItemModel::index() na potrzeby testów
 */
void ModelTest::index()
{
    // Upewnij się, że niepoprawne wartości prowadzą do zwrócenia nieważnego indeksu
    Q_ASSERT(model->index(-2, -2) == QModelIndex());
    Q_ASSERT(model->index(-2, 0) == QModelIndex());
    Q_ASSERT(model->index(0, -2) == QModelIndex());

    int rows = model->rowCount();
    int columns = model->columnCount();

    if (rows == 0)
        return;

	// wartości brzegowe
    Q_ASSERT(model->index(rows, columns) == QModelIndex());
    Q_ASSERT(model->index(0, 0).isValid() == true);

    // Upewnij się, że zawsze zwracany jest ten sam indeks
    QModelIndex a = model->index(0, 0);
    QModelIndex b = model->index(0, 0);
    Q_ASSERT(a == b);

    // index() jest testowana dokładniej w checkChildren(),
    // ale to wystarczy do wychwycenia poważnych błędów
}

/*!
	Implementacja QAbstractItemModel::parent() na potrzeby testów
 */
void ModelTest::parent()
{
    // Upewnij się, że model nie doprowadzi do awarii i zwróci nieważny QModelIndex
    // gdy zostanie poproszony o rodzica nieważnego indeksu.
    Q_ASSERT(model->parent(QModelIndex()) == QModelIndex());

    if (model->rowCount() == 0)
        return;

    // Kolumna 0               | Kolumna 1   |
    // QModelIndex()           |             |
    //    \- topIndex          | topIndex1   |
    //         \- childIndex   | childIndex1 |

    // Test na popularny błąd numer #1. Upewnij się, że indeks najwyższego poziomu ma rodzica
    // który jest nieważnym QModelIndex.
    QModelIndex topIndex = model->index(0, 0, QModelIndex());
    Q_ASSERT(model->parent(topIndex) == QModelIndex());

    // Test na popularny błąd numer #2. Upewnij się, że indeks drugiego poziomu ma rodzica
    // który jest indeksem najwyższego poziomu.
    if (model->rowCount(topIndex) > 0) {
        QModelIndex childIndex = model->index(0, 0, topIndex);
        Q_ASSERT(model->parent(childIndex) == topIndex);
    }

    // Test na popularny błąd numer #3. Druga kolumna NIE powinna mieć tych samych dzieci
    // co pierwsza kolumna w wierszu.
    // Z reguły druga kolumna wcale nie powinna mieć dzieci.
    QModelIndex topIndex1 = model->index(0, 1, QModelIndex());
    if (model->rowCount(topIndex1) > 0) {
        QModelIndex childIndex = model->index(0, 0, topIndex);
        QModelIndex childIndex1 = model->index(0, 0, topIndex1);
        Q_ASSERT(childIndex != childIndex1);
    }

    // Pełen test, przejdź na głębokość n poziomów modelu u sprawdź,
    // czy wszystkie dzieci poprawnie określają rodzica.
    checkChildren(QModelIndex());
}

/*!
    Wywoływana z testu parent().

	Model, który zwraca indeks rodzica X powinien również zwracać X
	poproszony o rodzica indeksu.

    Ta funkcja rekurencyjna w dość kompletny sposób testuje cały model,
	starając się wychwycić przypadki brzegowe.

    Funkcja zakłada, że rowCount(), columnCount() i index() działają poprawnie. 
    Jeśli w którejś z nich wystąpi błąd, zostanie on wychwycony, jednak podstawowe błędy
	powinny zostać zgłoszone przez testy zdefiniowane powyżej. 
	Na tym etapie trudniej już ustalić przyczynę problemu.
 */
void ModelTest::checkChildren(const QModelIndex &parent, int currentDepth)
{
    // Na początek spróbujmy cofnąć się w górę drzewa.
    QModelIndex p = parent;
    while (p.isValid())
        p = p.parent();

    // Dla modeli, które są wypełniane dynamicznie.
    if (model->canFetchMore(parent)) {
        fetchingMore = true;
        model->fetchMore(parent);
        fetchingMore = false;
    }

    int rows = model->rowCount(parent);
    int columns = model->columnCount(parent);

    if (rows > 0)
        Q_ASSERT(model->hasChildren(parent));

    // Dalsze testy oparte o rows(), columns() i hasChildren()
    Q_ASSERT(rows >= 0);
    Q_ASSERT(columns >= 0);
    if (rows > 0)
        Q_ASSERT(model->hasChildren(parent) == true);

    //qDebug() << "rodzic:" << model->data(parent).toString() << "wiersze:" << rows
    //         << "kolumny:" << columns << "kolumna rodzica:" << parent.column();

    Q_ASSERT(model->hasIndex(rows + 1, 0, parent) == false);
    for (int r = 0; r < rows; ++r) {
        if (model->canFetchMore(parent)) {
            fetchingMore = true;
            model->fetchMore(parent);
            fetchingMore = false;
        }
        Q_ASSERT(model->hasIndex(r, columns + 1, parent) == false);
        for (int c = 0; c < columns; ++c) {
            Q_ASSERT(model->hasIndex(r, c, parent) == true);
            QModelIndex index = model->index(r, c, parent);
            // rowCount() i columnCount() mówiły, że istnieje...
            Q_ASSERT(index.isValid() == true);

            // index() powinna zawsze zwracać ten sam indeks, wywołana dwa razy z rzędu
            QModelIndex modifiedIndex = model->index(r, c, parent);
            Q_ASSERT(index == modifiedIndex);

            // Upewnijmy się, że dostaniemy ten sam indeks, gdy poprosimy o niego dwa razy z rzędu
            QModelIndex a = model->index(r, c, parent);
            QModelIndex b = model->index(r, c, parent);
            Q_ASSERT(a == b);

            // Podstawowe testy zwróconego indeksu
            Q_ASSERT(index.model() == model);
            Q_ASSERT(index.row() == r);
            Q_ASSERT(index.column() == c);
            // Chociaż teoretycznie możesz zwrócić QVariant, z reguły jest to oznaka
            // błędu w data()  Jeśli w Twoim modelu ta sytuacja rzeczywiście jest dozwolona,
			// usuń ten fragment.
            //Q_ASSERT(model->data(index, Qt::DisplayRole).isValid() == true);

            // Jeśli kolejny test zawiedzie, oto przydatna informacja do debugowania
            /*
            if (model->parent(index) != parent) {
                qDebug() << r << c << currentDepth << model->data(index).toString()
                         << model->data(parent).toString();
                qDebug() << index << parent << model->parent(index);
                // Widok, za pomocą którego możesz wyświetlić model.
                //QTreeView view;
                //view.setModel(model);
                //view.show();
            }*/

            // Sprawdzenie, czy możemy odzyskać prawdziwego rodzica.
            QModelIndex p = model->parent(index);
            //qDebug() << "dziecko:" << index;
            //qDebug() << p;
            //qDebug() << parent;
            Q_ASSERT(model->parent(index) == parent);

            // rekurencyjnie przejdź przez dzieci
            if (model->hasChildren(index) && currentDepth < 10 ) {
                //qDebug() << r << c << "ma dzieci" << model->rowCount(index);
                checkChildren(index, ++currentDepth);
            }/* else { if (currentDepth >= 10) qDebug() << "sprawdzono 10 poziomów"; };*/

            // sprawdzenie, czy indeks nie zmienił się po testach dzieci
            QModelIndex newerIndex = model->index(r, c, parent);
            Q_ASSERT(index == newerIndex);
        }
    }
}

/*!
    Implementacja QAbstractItemModel::data() na potrzeby testów
 */
void ModelTest::data()
{
    // Niepoprawny indeks powinien zwrócić niepoprawny qvariant
    Q_ASSERT(!model->data(QModelIndex()).isValid());

    if (model->rowCount() == 0)
        return;

    // Poprawny indeks powinien mieć poprawne dane QVariant
    Q_ASSERT(model->index(0, 0).isValid());

    // nie powinno być możliwe ustawienie danych (setData()) na niepoprawnym indeksie
    Q_ASSERT(model->setData(QModelIndex(), QLatin1String("foo"), Qt::DisplayRole) == false);

    // role ogólnego przeznaczenia, które powinny zwracać QString
    QVariant variant = model->data(model->index(0, 0), Qt::ToolTipRole);
    if (variant.isValid()) {
        Q_ASSERT(variant.canConvert(QMetaType::QString));
    }
    variant = model->data(model->index(0, 0), Qt::StatusTipRole);
    if (variant.isValid()) {
        Q_ASSERT(variant.canConvert(QMetaType::QString));
    }
    variant = model->data(model->index(0, 0), Qt::WhatsThisRole);
    if (variant.isValid()) {
        Q_ASSERT(variant.canConvert(QMetaType::QString));
    }

    // role ogólnego przeznaczenia, które powinny zwracać QSize
    variant = model->data(model->index(0, 0), Qt::SizeHintRole);
    if (variant.isValid()) {
        Q_ASSERT(variant.canConvert(QMetaType::QSize));
    }

    // role ogólnego przeznaczenia, które powinny zwracać QFont
    QVariant fontVariant = model->data(model->index(0, 0), Qt::FontRole);
    if (fontVariant.isValid()) {
        Q_ASSERT(fontVariant.canConvert(QMetaType::QFont));
    }

    // Sprawdzenie, czy damy dany sposób wyrównania tekstu
    QVariant textAlignmentVariant = model->data(model->index(0, 0), Qt::TextAlignmentRole);
    if (textAlignmentVariant.isValid()) {
        int alignment = textAlignmentVariant.toInt();
        Q_ASSERT(alignment == Qt::AlignLeft ||
                 alignment == Qt::AlignRight ||
                 alignment == Qt::AlignHCenter ||
                 alignment == Qt::AlignJustify ||
                 alignment == Qt::AlignTop ||
                 alignment == Qt::AlignBottom ||
                 alignment == Qt::AlignVCenter ||
                 alignment == Qt::AlignCenter ||
                 alignment == Qt::AlignAbsolute ||
                 alignment == Qt::AlignLeading ||
                 alignment == Qt::AlignTrailing);
    }

    // role ogólnego przeznaczenia, które powinny zwracać QColor
    QVariant colorVariant = model->data(model->index(0, 0), Qt::BackgroundColorRole);
    if (colorVariant.isValid()) {
        Q_ASSERT(colorVariant.canConvert(QMetaType::QColor));
    }

    colorVariant = model->data(model->index(0, 0), Qt::TextColorRole);
    if (colorVariant.isValid()) {
        Q_ASSERT(colorVariant.canConvert(QMetaType::QColor));
    }

    // Sprawdzenie, czy stan (state) jest nam znany.
    QVariant checkStateVariant = model->data(model->index(0, 0), Qt::CheckStateRole);
    if (checkStateVariant.isValid()) {
        int state = checkStateVariant.toInt();
        Q_ASSERT(state == Qt::Unchecked ||
                 state == Qt::PartiallyChecked ||
                 state == Qt::Checked);
    }
}

/*!  
	Przechowaj to, co ma zostać wstawione, by sprawdzić, czy operacja się powiodła

    \sa rowsInserted()
 */
void ModelTest::rowsAboutToBeInserted(const QModelIndex &parent, int start, int end)
{
    Q_UNUSED(end);
    Changing c;
    c.parent = parent;
    c.oldSize = model->rowCount(parent);
    c.last = model->data(model->index(start - 1, 0, parent));
    c.next = model->data(model->index(start, 0, parent));
    insert.push(c);
}

/*!
    Potwierdź, że operacja się powiodła

    \sa rowsAboutToBeInserted()
 */
void ModelTest::rowsInserted(const QModelIndex & parent, int start, int end)
{
    Changing c = insert.pop();
    Q_ASSERT(c.parent == parent);
    Q_ASSERT(c.oldSize + (end - start + 1) == model->rowCount(parent));
    Q_ASSERT(c.last == model->data(model->index(start - 1, 0, c.parent)));
    /*
    if (c.next != model->data(model->index(end + 1, 0, c.parent))) {
        qDebug() << start << end;
        for (int i=0; i < model->rowCount(); ++i)
            qDebug() << model->index(i, 0).data().toString();
        qDebug() << c.next << model->data(model->index(end + 1, 0, c.parent));
    }
    */
    Q_ASSERT(c.next == model->data(model->index(end + 1, 0, c.parent)));
}

void ModelTest::layoutAboutToBeChanged()
{
    for (int i = 0; i < qBound(0, model->rowCount(), 100); ++i)
        changing.append(QPersistentModelIndex(model->index(i, 0)));
}

void ModelTest::layoutChanged()
{
    for (int i = 0; i < changing.count(); ++i) {
        QPersistentModelIndex p = changing[i];
        Q_ASSERT(p == model->index(p.row(), p.column(), p.parent()));
    }
    changing.clear();
}

/*!
    Przechowaj to, co ma zostać usunięte, by sprawdzić, czy operacja się powiodła

    \sa rowsRemoved()
 */
void ModelTest::rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end)
{
    Changing c;
    c.parent = parent;
    c.oldSize = model->rowCount(parent);
    c.last = model->data(model->index(start - 1, 0, parent));
    c.next = model->data(model->index(end + 1, 0, parent));
    remove.push(c);
}

/*!
    Potwierdź, że operacja się powiodła

    \sa rowsAboutToBeRemoved()
 */
void ModelTest::rowsRemoved(const QModelIndex & parent, int start, int end)
{
    Changing c = remove.pop();
    Q_ASSERT(c.parent == parent);
    Q_ASSERT(c.oldSize - (end - start + 1) == model->rowCount(parent));
    Q_ASSERT(c.last == model->data(model->index(start - 1, 0, c.parent)));
    Q_ASSERT(c.next == model->data(model->index(start, 0, c.parent)));
}

