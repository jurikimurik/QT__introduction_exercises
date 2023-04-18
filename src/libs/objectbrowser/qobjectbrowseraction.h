#ifndef QOBJECTBROWSERACTION_H
#define QOBJECTBROWSERACTION_H

#include "qobjectbrowser.h"
#include <QAction>
#include <QScopedPointer>

/** Przełącz początkowo niewidoczne okno QObjectBrowser. 
    Użycie: utwórz instancję i dodaj ją do menu tools/view/context.
*/
class OBJECTBROWSER_EXPORT QObjectBrowserAction : public QAction {
    Q_OBJECT
public:
    /** @param parent - obiekt-rodzic (odpowiedzialny za zniszczenie tej instancji
        i przełączanego widżetu) */
    QObjectBrowserAction(QObject* parent=0);
    bool isChecked() const;
public slots:
    void setChecked(bool);
    void checkCheck();
private:
    QScopedPointer<QObjectBrowser> m_browser; /* Obiekt "zarządzany",
        który nie traktuje this jako rodzica. Jednak w sposób typowy dla rodzica,
        gdy this zostanie zniszczony, zniszczeniu ulegnie również przeglądarka. */
};

#endif        //  #ifndef QOBJECTBROWSERACTION_H
