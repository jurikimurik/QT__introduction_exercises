#ifndef ACTIONEDITORDIALOG_H
#define ACTIONEDITORDIALOG_H

#include "ui_actioneditordialog.h"
class QAction;
#include <QShortcut>
#include <QString>
#include <QDialog>
#include <QList>
#include <QKeySequence>
#include "actioneditor_export.h"

/** Okno dialogowe do edycji pojedynczej akcji.
	 Przechwytuje sekwencję QKeySequence i wyświetla ją w QLineEdit.
	 @author Alan Ezust
*/

class ACTIONEDITOR_EXPORT ActionEditorDialog : public QDialog, private Ui::ActionEditorDialog {
	Q_OBJECT
public:
    /** @param action - akcja, której skrót chcemy edytować */
	explicit ActionEditorDialog(QAction* action, QWidget* parent = 0);
	void keyPressEvent(QKeyEvent*);

	/** @return klawisze wciśnięte od czasu ostatniego użycia przycisku "Wyczyść" */
	QKeySequence keySequence() const {return m_sequence;}

protected slots:
	void on_m_clearButton_clicked();
	void updateUi();
protected:
	void changeEvent(QEvent* e);
private:
	QKeySequence m_sequence;
	QAction* m_action;
	QList<QPair<int, int> > m_events;

};

#endif // ACTIONEDITORDIALOG_H
