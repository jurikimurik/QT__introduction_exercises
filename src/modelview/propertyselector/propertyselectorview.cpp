#include "propertyselectorview.h"
#include "propertyselectormodel.h"
#include <QAbstractListModel>
#include <QWidget>
#include <QListView>
#include <QToolBar>
#include <QAction>
#include <QActionGroup>
#include <QObject>
#include <QSize>
#include <QDebug>
//start id=constructor
PropertySelectorView::
PropertySelectorView(QAbstractListModel* model, QWidget* parent) :
QMainWindow(parent) {
    m_ListView = new QListView(this);
    setCentralWidget(m_ListView);
    PropertySelectorModel* chdmodel(qobject_cast<PropertySelectorModel*>(model));
    m_ListView->setModel(chdmodel);
    m_ListView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    m_ListView->setSelectionBehavior(QAbstractItemView::SelectRows);
    QToolBar* toolbar = new QToolBar("Akcje", this);
    m_ActionGroup = new QActionGroup(this);
    m_ApplyAction = addChoice("Apply", "Zastosuj zmiany");
    m_CancelAction = addChoice("Cancel", "Anuluj zmiany"); 
    toolbar->addActions(m_ActionGroup->actions());
    QMainWindow::addToolBar(Qt::TopToolBarArea, toolbar);
    connect(m_CancelAction, SIGNAL(triggered(bool)), 
                     this, SLOT(closeWindow(bool)));
    connect(m_ApplyAction, SIGNAL(triggered(bool)), 
                     this, SLOT(sendSelects(bool)));
}
//end
/** Po zaznaczeniu przez użytkownika nagłówków, metoda pobiera listę indeksów
zaznaczonych elementów i za pomocą sygnału przesyła ją do modelu.
*/
//start id=selects
void PropertySelectorView::sendSelects(bool) {
    QItemSelectionModel* selectModel = m_ListView->selectionModel();
    QModelIndexList selects = selectModel->selectedIndexes();
    emit selectionsMade(selects);
}
//end

void PropertySelectorView::closeWindow(bool) {
    setVisible(false);
}

/** Ta metoda to zrefaktoryzowany kod tworzący akcje
*/
QAction* PropertySelectorView::addChoice(QString name, QString text) {
    QAction* retval = new QAction(text, this);
    retval->setObjectName(name);
    retval->setEnabled(true);
    m_ActionGroup->addAction(retval);
    return retval;
}

/** Ten slot jest wywoływany przez przywróceniem widzialności widoku.
Jest wywoływany przez sygnał w modelu, który transmituje listę indeksów
zaznaczonych elementów, by widoczne były ostatnie zaznaczone elementy.
*/
void PropertySelectorView::restoreSelects(QList<QPersistentModelIndex> selects) {
    QItemSelectionModel* selectModel = m_ListView->selectionModel();
    foreach(QPersistentModelIndex indx, selects) 
        selectModel->select(indx, QItemSelectionModel::Select);
}

