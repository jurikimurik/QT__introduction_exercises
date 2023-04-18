#ifndef ACTIONSDIALOG_H
#define ACTIONSDIALOG_H

#include <QAction>
#include <QList>
#include <QWidget>
#include <QTableWidget>

/** Oparte o kod Qt3 z numery 14 kwartalnika Qt Quarterly.
    Zaktualizowane do Qt 4.6 przez Alana Ezusta */
class ActionsDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ActionsDialog(const QList<QAction*>& actions, QWidget* parent = 0);

protected slots:
    void accept();

private slots:
    void recordAction(int row, int column);
    void validateAction(int row, int column);

private:
    QString m_oldAccelText;
    QTableWidget* m_actionsTable;
    QList<QAction*> m_actionsList;
};

#endif
