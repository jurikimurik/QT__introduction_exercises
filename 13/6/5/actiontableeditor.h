#ifndef ACTIONTABLEEDITOR_H
#define ACTIONTABLEEDITOR_H
#include "actioneditor_export.h"
#include <QDialog>
#include <QList>
#include "actioneditor_export.h"

class QModelIndex;
class QAction;
class QSortFilterProxyModel;
class ActionTableModel;

namespace Ui {
  class ActionTableEditor;   /* zapowiedź klasy w przestrzeni nazw */
};

/** Okno dialogowe do edycji skrótów klawiszowych w widoku tablicowym.
    Zainspirowane przez przykład Qt3 example z qq14.
    Użycie: wywołaj restoreShortcuts() podczas inicjalizacji programu, by przywrócić
    poprzednio zdefiniowane skróty zapisane w QSettings.
    Następnie wywołaj funkcję ActionTableEditor::exec(), który obsłuży wszystko inne,
	w tym zapisze zmienione skróty w  QSettings.
    @author alan ezust
*/
class ACTIONEDITOR_EXPORT ActionTableEditor : public QDialog {

	Q_OBJECT
 public:
	/** Tworzy listę akcji w oparciu o informacje pozyskane przez 
		qApp->findChildren i dzieci widżety najwyższego poziomu. */
	explicit ActionTableEditor(QWidget* parent=0);

	/** @param actions - list of actions to present in table */
	explicit ActionTableEditor(QList<QAction*> actions, QWidget* parent=0);

	virtual ~ActionTableEditor();

	/** @return lista akcji QAction odnalezionych w trakcie przejścia przez drzewa
	  QObject w qApp i widżecie najwyższego poziomu. */
	static QList<QAction*> allActions();

	/** Przywraca sktóry, które zostały poprzednio zapisane przy użyciu tej tabeli
		@param actions lista akcji QAction do przywrócenia */
	static void restoreShortcuts(QList<QAction*> actions = allActions()) ;

protected slots:
	void on_m_tableView_activated(const QModelIndex& idx);      /* Slot podłączony automatycznie */
	void on_m_filterField_textChanged(const QString& newText);  /* Slot podłączony automatyczniet */
	/** Zapisz zmienione skróty w QSettings */
	void accept();

protected:
	void setupSortFilter();
	void changeEvent(QEvent* e);

private:
	ActionTableModel* m_model;
	QSortFilterProxyModel* m_sortFilterProxy;
	Ui::ActionTableEditor* m_ui;            /* Obiekt ui Designera */
	QList<QAction*> m_changedActions;
};

#endif        //  #ifndef ACTIONTABLEEDITOR_H
